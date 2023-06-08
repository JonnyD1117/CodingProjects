#include <iostream>
#include <filesystem>
#include "JsonParser.h"

#include <fstream>




int main() {

    std::filesystem::path path1 = "/home/indy/repos/CodingProjects/JsonParser/test_files/test_file.json";
    std::filesystem::path path2 = "/home/indy/repos/CodingProjects/JsonParser/test_files/dummy_file.json";
    std::filesystem::path path3 = "/home/indy/repos/CodingProjects/JsonParser/test_files/test_file_3.json";

    JsonLexer lex(path1);
    JsonToken tok;

    while(!lex.isEOF())
    {
        tok = lex.NextToken();
        tok.Print();
    }


    return 0;
}
