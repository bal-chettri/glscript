#include <stdio.h>
#include <string.h>

#include <tokenizer/tokenizer.h>

int main () {
    const sys_tchar *message = 
    _tx("this is a sample message.");
    
    sys_tchar *input = (sys_tchar *)message;
    
    Tokenizer tokenizer;
    Tokenizer::Token tokens [100];
    size_t num_tokens;
    
    num_tokens = tokenizer.Tokenize ( &input, tokens, sizeof(tokens) / sizeof(tokens[0]) );
    
    sys_tprintf ( "Token count: %ld\n", num_tokens );
    
    Tokenizer::DumpTokens (tokens, num_tokens);
    
    return 0;
}
