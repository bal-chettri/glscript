//
// gl_script_preprocessor.h  glscript script preprocessor.
// 
// This file is part of glScript project.
//
//   glScript is free software: you can redistribute it and/or modify
//   it under the terms of the GNU Lesser General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
//   glScript is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU Lesser General Public License for more details.
//
//   You should have received a copy of the GNU Lesser General Public License
//   along with glScript. If not, see <http://www.gnu.org/licenses/>.
//
//   Copyright (c) 2012 Bal Bahadur Chettri
//
//   Author: Bal Bahadur Chettri (balu.chettri@gmail.com)
//
#ifndef __GLSCRIPT_SCRIPT_PREPROCESSOR_H__
#define __GLSCRIPT_SCRIPT_PREPROCESSOR_H__

#include <glscript/gls_types.h>
#include <glscript/gls_obj.h>
#include <glscript/gls_script_source.h>

#include <asynch/asynch.h>
#include <tokenizer/tokenizer.h>
#include <sysport/sysport.h>

#include <vector>
#include <string>

namespace gls {

/**
 * PreprocessorError enumeration. Defines preprocessor error codes.
 */
enum /* PreprocessorError */ {
	kPrepErrorNone,								/** no error (success) */
	kPrepErrorOutOfMemory,						/** memory allocation error */
	kPrepErrorSyntaxParse,						/** syntax error while parsing */
	kPrepErrorInvalidCommand,					/** invalid preprocessor directive */
	kPrepErrorLanguageRedefined,				/** language redefined */
	kPrepErrorTooManyTokens,					/** too many tokens found */
	kPrepErrorTooLongToken,						/** token length is to big */
	kPrepErrorInvalidPathSpec,					/** invalid path format or specification */
	kPrepErrorUnterminatedBlock,				/** preprocessor block is unterminated */
	kPrepErrorLoadScriptFailed,					/** failed to load included script */
	kPrepErrorPreprocessFailed					/** general preprocessing failed */
};

/**
 * PreprocessorCommandType enumeration. Defines preprocessor command type constants.
 */
enum PreprocessorCommandType {
	kPrepCommandTypeInvalid = -1,				/** invalid command type */
	kPrepCommandTypeLanguage,					/** language directive */
	kPrepCommandTypeInclude						/** include directive */
};

/**
 * PreprocessorCommand structure. Stores preprocessor command information.
 */
struct PreprocessorCommand {
	PreprocessorCommandType type;				/** type of the directive */
	Tokenizer::Token token;						/** token for command's parameter */
};

class ScriptPreprocessor;

/**
 * PreprocessorBlock class.
 *
 * A preprocessor block (<# #>) in a script source. This class is responsible for actually
 * parsing a preprocessor block and pre-processing it. During pre-processing, all preprocessor
 * directives are handled and necessary actions are taken. This class is also responsible
 * for actually expanding the block after it has been pre-processed.
 */
class PreprocessorBlock {
	// public methods...
public:
	/** 
	 * PreprocessorBlock constructor.
	 * @param start pointer to the start of the block i.e. '<' char in current script source
	 * @param end pointer to the end of the block i.e. '>' in current script source
	 * @param pScriptSource pointer to the current script source object
	 */
	PreprocessorBlock (const sys_wchar *start, const sys_wchar *end, 
								ScriptSource *pScriptSource,
								ScriptPreprocessor *pPreprocessor);

	/** PreprocessorBlock destructor. */
	virtual ~PreprocessorBlock ();

	/** Returns a pointer to the start of the preprocessor block i.e. '<' */
	inline const sys_wchar *GetBlockStart () const {
		return m_pBlockStart;
	}
	
	/** Returns a pointer to the end of the preprocessor block i.e. '>' */
	inline const sys_wchar *GetBlockEnd () const {
		return m_pBlockEnd;
	}

	/** Returns a pointer to the inner text of the preprocessor block i.e. text 
	    immediately following '#' character in <# */
	inline const sys_wchar *GetInnerText () const {
		return m_pBlockStart + 1;
	}

	/** Returns the length of the block including the enclosers <# and #>. */
	inline size_t GetLength() const {
		return m_pBlockEnd - m_pBlockStart + 1;
	}

	/** Returns the length of the inner text. */
	inline size_t GetInnerTextLength() const {
		return GetLength() - 4;
	}

	/** Returns the expanded length of the block. */
	size_t GetExpandedLength() const;

	/** Returns the language set for the block */
	const tstring &GetLanguage () const;

	/** parses the block */
	int ParseBlock ();

	/* pre-processes the block */
	int ProcessBlock ();

	/** expands the block */
	int ExpandBlock (sys_wchar **p_pCodeBuffer);

	// internal private methods...
private:

	/** Parses the command tokens */
	int ParseCommand (const Tokenizer::Token *tokens, size_t count_tokens);
	
	/** Parses the 'include' command tokens */
	int ParseCommand_Include (const Tokenizer::Token *tokens, size_t count_tokens);
	
	/** Parses the 'language' command tokens */
	int ParseCommand_Language (const Tokenizer::Token *tokens, size_t count_tokens);

	int ProcessCommand_Include (PreprocessorCommand &cmd);
	int ProcessCommand_Language (PreprocessorCommand &cmd);

	void Cleanup ();

	// private data members...
private:
	const sys_wchar		*m_pBlockStart;						/** start of the block */
	const sys_wchar		*m_pBlockEnd;						/** end of the block */
	ScriptSource		*m_pScriptSource;					/** script source object (not addref'ed) */
	ScriptPreprocessor	*m_pPreprocessor;					/** script preprocessor (not addref'ed) */
	tstring				m_language;							/** block's 'language' value */

	vector<PreprocessorCommand> m_commands;					/** commands */
	vector<ScriptSource *> m_inc_sources;					/** include sources */
};

/**
 * ScriptPreprocessor class.
 *
 * Preprocesses the script source and generates a flattened or expanded script source.
 * The flattened script source may then be passed to the scripting host for execution.
 */
class ScriptPreprocessor : public RefObject {
	// private methods...
private:		

	/** 
	 * ScriptPreprocessor constructor. Constructs a preprocessor object with a script source  
	 * to be preprocessed.
	 * Note: The constructor is private because you don't create the preprocessor objects 
	 * directly. Use public static factory methods to create a preprocessor object.
	 */
	ScriptPreprocessor (ScriptSource *pSourceScript);

	/** ScriptPreprocessor destructor. */
	virtual ~ScriptPreprocessor ();

public:
	/** Returns the script source object. The caller must call Release() on after using it. */
	ScriptSource *GetSourceScript ();

	/** Begins the preprocessing. */
	int Preprocess ();

	/** Returns the flattened script source. The caller must call Release() on after using it. */
	ScriptSource *GetFlattenedScriptSource ();

	// internal private methods...
private:
	/** Finds the blocks in the script source */
	int FindBlocks ();

	/** Finds the start of next block from the specified position in the script source. */
	const sys_wchar *FindBlockStart (const sys_wchar *position);

	/** Finds the end of next block from the specified position in the script source. */
	const sys_wchar *FindBlockEnd (const sys_wchar *position);	

	/** Processes all blocks. */
	int ProcessBlocks () ;

	/** Flattens or expands all blocks. */
	int FlattenBlocks ();

	/** Returns the length of all blocks in script source */
	size_t GetBlocksLength () const;

	/** Returns the length of the script source excluding the blocks length i.e.
	    m_pScriptSource->GetLength() - GetBlocksLength() */
	size_t GetScriptLength () const;

	/** Sets search paths for 'include' directive */
	void SetIncludeSearchPaths (const std::vector<tstring> &search_paths);

	/** Sets the parent preprocessor object */
	void SetParentPreprocessor (ScriptPreprocessor *);

private:
	/** script source object */
	ScriptSource *m_pScriptSource;

	/** language of the script source */
	tstring m_language;

	/** flattened script source object */
	ScriptSource *m_pFlattenedScriptSource;

	/** preprocessor blocks */
	vector<PreprocessorBlock> m_blocks;	
		
	/** search paths for 'include' directive */
	std::vector<tstring> m_search_paths;

	/** points to the parent preprocessor object (if set). This allows us to 
		inherit or reuse some of the properties like 'search paths' during the 
		preprocessing phase. */
	ScriptPreprocessor *m_parent_preprocessor;

	// public static factory methods...
public:
	// creates a preprocessor object with specified parameters and configuration
	static ScriptPreprocessor *CreatePreprocessor ( const sys_tchar *url, 
														ScriptPreprocessor *parent,
														const std::vector<tstring> &search_paths,
														int &retcode);

	/** 
	 * Creates a preprocessor object by loading script source from specified URL
	 * and returns it after preprocessing the script source.
	 */
	static ScriptSource *PreprocessScript (const sys_tchar *url, int &ret);

	/** 
	 * Same as above except it allows to pass in search paths for 'include'
	 * directive.
	 */
	static ScriptSource *PreprocessScript (const sys_tchar *url, 
												ScriptPreprocessor *parent,
												const std::vector<tstring> &search_paths, 
												int &ret);

	/** 
	 * #TODO: Implementation
	 * Creates a preprocessor object by loading script source from specified URL
	 * asynchronously and returns it after preprocessing the script source. 
	 * #TODO: Return ScriptSource in callback.
	 */
	static ScriptSource *PreprocessScript (const sys_tchar *url, 
											 const ASYNCH_CALLBACK callback, 
											 void *context = NULL);

	/** Translates the specified error code into a readable error message. */
	static const sys_tchar *TranslateErrorCode (int err_code);

	// friends
	friend class PreprocessorBlock;
};

}; // gls namespace

#endif /* !__GLSCRIPT_SCRIPT_PREPROCESSOR_H__ */
