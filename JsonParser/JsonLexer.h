#pragma once
#include <variant>

class JsonLexer {

private:
    std::ifstream file;
    JsonToken token;
    std::variant<std::string, char, size_t> token_val;

    char cur_char;

    void buildToken(JsonTokenTypes type, std::variant<std::string, char, size_t> value)
    {
        token.value_ = value;
        token.type_ = type;
    }

    void makeString()
    {
        std::string str {cur_char};

        nextCharacter();

        while(cur_char != '"' && !file.eof())
        {
            str.append(&cur_char);
            nextCharacter();
        }

        str.append(&cur_char);

        buildToken(JsonTokenTypes::STRING, str);
    }

    void makeNumber()
    {
        std::string num {cur_char};

        size_t fs_check = 0;

        nextCharacter();

        while(isdigit(cur_char) || cur_char =='.' && !file.eof() && fs_check <1)
        {
            num.append(&cur_char);
            nextCharacter();
        }

        buildToken(JsonTokenTypes::NUMBER, num);
    }

    void makeBoolean()
    {
        std::string str {cur_char};

        nextCharacter();

        while(!file.eof())
        {
            // cur_char != ' ' &&
            if(isalpha(cur_char))
            {
                str.append(&cur_char);
                nextCharacter();
            }
            else
            {
                break;
            }
        }

        if(str == "true")
        {
            buildToken(JsonTokenTypes::TRUE, str);
        }
        else if (str == "false")
        {
            buildToken(JsonTokenTypes::FALSE, str);
        }
    }

    void makeNull()
    {
        std::string str {cur_char};

        nextCharacter();

        while(!file.eof())
        {
            // cur_char != ' ' &&
            if(isalpha(cur_char))
            {
                str.append(&cur_char);
                nextCharacter();
            }
            else
            {
                break;
            }
        }

        buildToken(JsonTokenTypes::NONE, str);
    }

    void nextCharacter() { file.get(cur_char); }

    std::string cast2String(char tmp) { return std::string {tmp}; }

public:

    bool isEOF() { return file.eof(); }

    JsonLexer(std::filesystem::path InputPath) : file(InputPath) {}

    JsonToken NextToken()
    {
        token.Clear();

        // Clear Token
        token.Clear();

        // Fetch the Next Character
        nextCharacter();

        // Evaluate Character
        if(file.eof()) { buildToken(JsonTokenTypes::ENDOFFILE, ""); }
        else if(cur_char == ' ') { }
        else if(cur_char == '"' ) { makeString(); }
        else if(isdigit(cur_char)) { makeNumber(); }
        else if (cur_char == 'f' || cur_char == 't') { makeBoolean(); }
        else if (cur_char == 'n') { makeNull(); }
        else if(cur_char == ',' ){ buildToken(JsonTokenTypes::COMMA, cast2String(',')); }
        else if(cur_char == '.' ){ buildToken(JsonTokenTypes::FULLSTOP, cast2String('.')); }
        else if(cur_char == ':' ){ buildToken(JsonTokenTypes::COLON, cast2String(':')); }
        else if(cur_char == '{' ){ buildToken(JsonTokenTypes::LBRACE, cast2String('{')); }
        else if(cur_char == '}' ){ buildToken(JsonTokenTypes::RBRACE, cast2String('}')); }
        else if(cur_char == '[' ){ buildToken(JsonTokenTypes::LBRACKET, cast2String('[')); }
        else if(cur_char == ']' ){ buildToken(JsonTokenTypes::RBRACKET, cast2String(']')); }
        else if(cur_char == '(' ){ buildToken(JsonTokenTypes::LPAREN, cast2String('(')); }
        else if(cur_char == ')' ){ buildToken(JsonTokenTypes::RPAREN, cast2String(')')); }

        return token;
    }
};
