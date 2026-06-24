/* TODO: Finish writing the specs for the lexing functions, figure out a way to neatly organize each token type

*/



// when parsing, ignore lines that being with ;, !, target, source_filename, attributes, $ 



token ClassifyToken(std::string str) {
    // if it starts with % its an identifier/variable
    // if it's a parenthesis treat it as a left paren token and right paren token
    // INCOMPLETE
    // treat any leftover random words as a keyword, will just drop later if it means nothing
}


std::vector<TokenType> LLVMFileLexer(std::string file_path) {
    // open an input file stream at the filepath
    // if unable, report an error and crash the program

    // create the token vector

    // read file in line by line, if the line starts with a forbidden character or word, move to the next line

    // for each word in the line (separated by spaces), identify token type
    // if not a valid token, then report compiler error

    // if a line begins with a forbidden string or char, skip the whole line

    // identify token type, then append token to the vector

    // continue until 



    // return the token vector
}

AST ParseLLVM(std::vector<TokenType> lexed_code){
    // read the file in character by character

    // if a line starts with a forbidden string or char, then skip it

    // 
}