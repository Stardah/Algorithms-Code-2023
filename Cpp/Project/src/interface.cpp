#include <format>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class ILabel {
public:
    virtual std::string BuildHTML() const = 0;

    virtual ~ILabel() = default;
};

class SimpleLabel : public ILabel {
public:
    SimpleLabel(std::string str) : _str(std::move(str)) {}

    std::string BuildHTML() const override {
        return std::format("<p> {} </p>", _str);
    }

private:
    std::string _str;
};

class DateLabel : public ILabel {
public:
    DateLabel(std::string dateStr) : _str(std::move(dateStr)) {}

    std::string BuildHTML() const override {
        return std::format("<p class=\"date\">Date: {}</p>", _str);
    }

private:
    std::string _str;
};

class IconLabel : public ILabel {
public:
    IconLabel(std::string str, std::string iconSrc) : _str(std::move(str)), _iconSrc(std::move(iconSrc)) {}

//    std::string BuildHTML() const override {
//        return std::format("<p><img src=\"{}\"/> {} </p>", _iconSrc, _str);
//    }

private:
    std::string _str;
    std::string _iconSrc;
};

int main() {
    std::vector<ILabel*> vecLabels;
    vecLabels.push_back(new SimpleLabel("Hello World"));
    vecLabels.push_back(new DateLabel("20th of February 2024"));
    vecLabels.push_back(new IconLabel("Error", "error.png"));

    std::string finalHTML;
    for (auto &label : vecLabels) {
        finalHTML += label->BuildHTML() + '\n';
    }

    std::cout << finalHTML;

    return 0;
}
