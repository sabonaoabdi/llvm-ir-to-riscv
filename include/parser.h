#ifndef PARSER_H_
#define PARSER_H_

#include <string>
#include <vector>
#include <unordered_set>

enum TokenType {
    kKeyword,
    kOperator,
    kIdentifier,
    kLiteral,
};

std::unorder<std::string>

struct Token {
    TokenType type;
    std::string value;
};



#endif // PARSER_H_