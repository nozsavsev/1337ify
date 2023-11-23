#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <io.h>
#include <fcntl.h>
using namespace std;

std::map<wstring, vector<wstring>> lookalikes{
  {L"A", {L"А" , L"Λ" , L"4"  }},
  {L"B", {L"В" , L"8" , L"|3" }},
  {L"C", {L"С" , L"(" , L"⌈"  }},
  {L"D", {L"Δ" , L"∂" , L"0"  }},
  {L"E", {L"Е" , L"Ё" , L"€"  }},
  {L"F", {L"ƒ" , L"ſ" , L"ʃ"  }},
  {L"G", {L"6" , L"9" , L"&"  }},
  {L"H", {L"Н" , L"Η" , L"|-|"}},
  {L"I", {L"І" , L"1" , L"|"  }},
  {L"J", {L"Ј" , L"ʝ" , L"∫"  }},
  {L"K", {L"К" , L"Κ" , L"<"  }},
  {L"L", {L"7" , L"1" , L"|__"}},
  {L"M", {L"М" , L"Μ" , L"//\\"}},
  {L"N", {L"И" , L"Ν" , L"//"}},
  {L"O", {L"О" , L"0" , L"Θ" }},
  {L"P", {L"Р" , L"Ρ" , L"¶" }},
  {L"Q", {L"9" , L"Ω" , L"O",L"О,"}},
  {L"R", {L"Я" , L"®" , L"12"}},
  {L"S", {L"5" , L"$" , L"§" }},
  {L"T", {L"Т" , L"†" , L"7"  }},
  {L"U", {L"Ц" , L"µ" , L"∪" }},
  {L"V", {L"/" , L"∨" , L"⋀" }},
  {L"W", {L"Ш" , L"// " ,L"ω" }},
  {L"X", {L"Х" , L"×" , L"+"  }},
  {L"Y", {L"У" , L"λ" , L"ʏ"  }},
  {L"Z", {L"2" , L"Ζ" , L"7"  }},
  {L"a", {L"α", L"@", L"ä"}},
  {L"b", {L"6", L"ß", L"β"}},
  {L"c", {L"(", L"¢", L"©"}},
  {L"d", {L"∂", L"ð", L"cl"}},
  {L"e", {L"ε", L"€", L"ɛ"}},
  {L"f", {L"ƒ", L"ſ", }},
  {L"g", {L"9", L"q", L"&"}},
  {L"h", {L"н", L"ħ", L"|-|"}},
  {L"i", {L"l", L"1", L"|"}},
  {L"j", {L"¿", L"ʝ", L"ł"}},
  {L"k", {L"к", L"₭", L"<"}},
  {L"l", {L"1", L"|", L"ł"}},
  {L"m", {L"м", L"nn", L"ηη"}},
  {L"n", {L"η", L"и", L"ń"}},
  {L"o", {L"0", L"ο", L"ø"}},
  {L"p", {L"ρ", L"q", L"¶"}},
  {L"q", {L"9", L"ϱ", L"g"}},
  {L"r", {L"я", L"г", L"®"}},
  {L"s", {L"5", L"$", L"§"}},
  {L"t", {L"τ", L"7", L"+"}},
  {L"u", {L"µ", L"ν", L"∪"}},
  {L"v", {L"∨", L"\/", L"√"}},
  {L"w", {L"ω", L"\/\/", L"vv"}},
  {L"x", {L"×", L"+", L"Х"}},
  {L"y", {L"γ", L"у", L"¥"}},
  {L"z", {L"2", L"ζ", L"7"}}
};

int random_arbitrary(int min, int max)
{
    return min + (rand() % (max - min + 1));
}

wstring randomLookalike(wstring letter)
{
    vector<wstring> lookalike = lookalikes[letter];
    return lookalike[random_arbitrary(0, lookalike.size() - 1)];
}

wstring leetify(wstring text)
{
    wstring result = L"";
    for (int i = 0; i < text.length(); i++)
    {
        wstring letter = text.substr(i, 1);
        if (lookalikes.find(letter) != lookalikes.end())
        {
            result += randomLookalike(letter);
        }
        else
        {
            result += letter;
        }
    }
    return result;
}

int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);

    wcout << leetify(L"fuck") << endl;


}