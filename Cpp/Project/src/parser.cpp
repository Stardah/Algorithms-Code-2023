#include <iostream>
#include <string>
#include <vector>
#include <regex>

enum class TokenType {
    UNDEFINED,
    WHITE_SPACES,
    NEWLINE,
    END_OF_FILE,
    INTEGER_VALUE,
    WORD,
};

struct Token {
    std::string value;
    TokenType type;
};

/*
class TokenBuilder {
public:
    TokenBuilder() = default;

    TokenBuilder& setType(TokenType type) {
        token_.type = type;
        return *this;
    }

    TokenBuilder& setValue(std::string value) {
        token_.value = value;
        return *this;
    }

    Token build() {
        return token_;
    }

private:
    Token token_ = {std::string(), TokenType::UNDEFINED};
};

{
    TokenBuilder().setType(TokenType::WHITE_SPACES).build();
}
*/

class TokenParser {
public:
    explicit TokenParser(std::string &input) : input_(input) {};

    bool isEmpty() const {
        return tokens_.empty();
    }

    TokenParser &parse(TokenType type) {
        std::regex_search(input_.cbegin() + offset_, input_.cend(), last_match_, token_regex_.at(type));
        if (!last_match_.empty()) {
            tokens_.push_back({last_match_.str(), type});
        }
        return *this;
    }

    TokenParser &thenParse(TokenType type) {
        if (!last_match_.empty()) {
            offset_ = last_match_.position() + last_match_.length();
        }
        return parse(type);
    }

    TokenParser &skip(TokenType type) {
        std::regex_search(input_.cbegin() + offset_, input_.cend(), token_regex_.at(type));
        if (!last_match_.empty()) {
            offset_ = last_match_.position() + last_match_.length();
        }
        return *this;
    }

    TokenParser &orElse(TokenType type) {
        if (isEmpty()) {
            return parse(type);
        }
        return *this;
    }

    std::vector<Token> getTokens() const {
        return tokens_;
    }

private:
    std::string &input_;
    std::smatch last_match_;
    long long offset_ = 0;
    std::vector<Token> tokens_;
    std::map<TokenType, std::regex> token_regex_ = {
            {TokenType::UNDEFINED,     std::regex(".*")},
            {TokenType::WHITE_SPACES,  std::regex(R"(\s+)")},
            {TokenType::NEWLINE,       std::regex("\n")},
            {TokenType::END_OF_FILE,   std::regex("\0")},
            {TokenType::INTEGER_VALUE, std::regex("[-+]?[0-9]+")},
            {TokenType::WORD,  std::regex("[a-zA-Z_][a-zA-Z0-9_]*")},
    };
};

int main() {
    std::string input = "Hello World!";
    auto tokens = TokenParser(input)
            .parse(TokenType::WORD)
            .orElse(TokenType::WORD)
            .getTokens();
//            .skip(TokenType::WHITE_SPACES)
//            .parse(TokenType::COMMAND_NAME).getTokens();

    for (const auto &token: tokens) {
        std::cout << token.value << std::endl;
    }
}