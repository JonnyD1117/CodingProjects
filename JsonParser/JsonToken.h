#pragma once

#include <string>
#include <variant>
#include <map>

enum class JsonTokenTypes
{
    UNDEFINED,
    COMMA,
    COLON,
    FULLSTOP,
    PLUS,
    MINUS,
    WHITESPACE,
    LBRACE,
    RBRACE,
    LPAREN,
    RPAREN,
    LBRACKET,
    RBRACKET,
    NUMBER,
    STRING,
    TRUE,
    FALSE,
    NONE,
    ENDOFFILE = -1,
};


struct JsonToken
{
    JsonTokenTypes type_ = JsonTokenTypes::UNDEFINED;
    std::variant<std::string, char, size_t> value_;

    std::map<JsonTokenTypes, std::string> ENUM_MAP
    {
        {JsonTokenTypes::UNDEFINED, "UNDEFINED"},
        {JsonTokenTypes::COMMA, "COMMA"},
        {JsonTokenTypes::COLON, "COLON"},
        {JsonTokenTypes::FULLSTOP, "FULLSTOP"},
        {JsonTokenTypes::PLUS, "PLUS"},
        {JsonTokenTypes::MINUS, "MINUS"},
        {JsonTokenTypes::WHITESPACE, "WHITESPACE"},
        {JsonTokenTypes::LBRACE, "LBRACE"},
        {JsonTokenTypes::RBRACE, "RBRACE"},
        {JsonTokenTypes::LBRACKET, "LBRACKET"},
        {JsonTokenTypes::RBRACKET, "RBRACKET"},
        {JsonTokenTypes::LPAREN, "LPAREN"},
        {JsonTokenTypes::RPAREN, "RPAREN"},
        {JsonTokenTypes::NUMBER, "NUMBER"},
        {JsonTokenTypes::STRING, "STRING"},
        {JsonTokenTypes::TRUE, "TRUE"},
        {JsonTokenTypes::FALSE, "FALSE"},
        {JsonTokenTypes::NONE, "NONE"},
        {JsonTokenTypes::ENDOFFILE, "ENDOFFILE"}

    };

    void Clear()
    {
        type_ = JsonTokenTypes::UNDEFINED;
        value_.emplace<0>();
    }

    void Print()
    {
        if(type_ != JsonTokenTypes::UNDEFINED)
        {
            std::cout << "(" << ENUM_MAP[type_] << " --> " << std::get<std::string>(value_) << ")"  << std::endl;
        }
    }
};