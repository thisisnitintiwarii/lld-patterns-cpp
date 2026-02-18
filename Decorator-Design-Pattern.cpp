// Decorator Design pattern

#include <bits/stdc++.h>
using namespace std;

class TextView{
public:
    virtual void render() = 0;
    virtual ~TextView(){};
};

class PlainTextView : public TextView{
    string str;
public:
    PlainTextView(const string& s){
        str = s;
    }
    void render() override {
        cout << str <<" This is plain text \n";
    }
};

class TextDecorator : public TextView{
protected:
    TextView* tv;
public:
    TextDecorator(TextView* textView) : tv(textView){};
};

class BoldDecorator: public TextDecorator{
public:
    BoldDecorator(TextView* textview) : TextDecorator(textview){};
    void render() override {
        cout << "<b>\n";
        tv->render();
        cout << "</b>\n";
    }
};

class UnderLineDecorator: public TextDecorator{
public:
    UnderLineDecorator(TextView* textview) : TextDecorator(textview){};
    void render() override {
        cout << "<I>\n";
        tv->render();
        cout << "</I>\n";
    }
};

class Italic: public TextDecorator{
public:
    Italic(TextView* textview) : TextDecorator(textview){};
    void render() override {
        cout << "<I>\n";
        tv->render();
        cout << "</I>\n";
    }
};

int main() {
    TextView* text = new PlainTextView("This is my New Text");

    text->render();

    TextView* bold = new BoldDecorator(text);
    bold->render();

    TextView* itl = new Italic(bold);
    itl->render();

    return 0;
}
