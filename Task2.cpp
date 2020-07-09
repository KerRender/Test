#include <iostream>
#include <string>
#include <vector>
#include <map>



std::map <int, std::string> lower_Tens =
{
    {1, "ten"}, {11, "eleven"}, {12, "twelve"}, {2, "twenty"}, {3, "thirty"}, {4, "fourty"}, {5, "fifty"},
    {6, "sixty"}, {7, "seventy"}, {8, "eighty"}, {9, "ninety"}
};
std::map <int, std::string> lower_Units =
{
    {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, 
    {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}, {0, "zero"}
};
std::map <int, std::string> upper_Tens =
{
    {1, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {2, "Twenty"}, {3, "Thirty"}, {4, "Fourty"}, {5, "Fifty"},
    {6, "Sixty"}, {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"}
};
std::map <int, std::string> upper_Units =
{
    {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"},
    {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {0, "Zero"}
};



int main()
{
    int x;
    std::string finale = "";
    std::cin >> x;
    if (x >= 0 && x <= 1000000000) {
        std::string num = std::to_string(x);

        if (x >= 0 && x <= 999) {

            switch (num.length()) {
            case 3: {
                int count = 0;

                for (int i = 0; i < num.length(); i++) {

                    if (num[i] == '0') {
                        count++;
                        continue;
                    }
                }

                if (count == 1) {

                    if (num == "11")
                        finale += upper_Tens[11];
                    else
                        finale += upper_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                }
                else if (count == 2) {
                    auto y = upper_Units[num[0] - '0'];
                    finale += y + " dollar";
                }
                else if (count == 0) {
                    auto y = upper_Units[num[0] - '0'];

                    if (num[1] == 0)
                        finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                    else {

                        if (num[2] == '0')
                            finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                        else {
                            num.erase(0, 1);

                            if (num == "11")
                                finale += y + " hundred " + lower_Tens[11] + " dollars";
                            else if (num == "12")
                                finale += y + " hundred " + lower_Tens[12] + " dollars";
                            else
                                finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                        }
                    }
                }
                break;
            }
            case 2: {
                if (num[1] == '0')
                    finale += upper_Tens[num[0] - '0'];
                else
                    if (num == "11")
                        finale += upper_Tens[11];
                    else
                        finale += upper_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";
                break;
            }
            case 1: {
                auto y = upper_Units[std::stoi(num)];
                finale += y + " dollar";
                break;
            }
            }
        }
        else if (x >= 1000 && x <= 999999) {
            switch (num.length()) {
            case 6: {
                int count = 0;

                for (int i = 0; i < num.length(); i++) {
                    
                    if (num[i] == '0') {
                        num.erase(0, 1);
                        count++;
                        continue;
                    }
                }

                switch (count) {
                case 0: {
                    // making thousands

                    // making hundreds

                    finale += upper_Units[num[0]-'0'] + " hundred ";
                    num.erase(0, 1);

                    // making tens
                    if (num[0] == '0') {
                        if (num[1] != '0')
                            finale += lower_Units[num[1] - '0'] + " thousand ";
                        else
                            finale += " thousand";
                    }
                    else {

                        if (num[0] == 1)
                            switch (num[1]) {
                            case 1:
                                finale += lower_Tens[11] + " thousand ";
                            case 2:
                                finale += lower_Tens[12] + " thousand ";
                            }
                        else {
                            
                            if (num[1] == '0')
                                finale += lower_Tens[num[0] - '0'] + " thousand ";
                            else
                                finale += lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " thousand ";
                        }
                    }

                    num.erase(0, 2);

                    // making hundreds
                    int count = 0;

                    for (int i = 0; i < num.length(); i++) {

                        if (num[i] == '0') {
                            count++;
                            continue;
                        }
                    }

                    if (count == 1) {

                        if (num == "11")
                            finale += lower_Tens[11] + " dollars";
                        else
                            finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                    }
                    else if (count == 2) {
                        auto y = lower_Units[num[0] - '0'];
                        finale += y + " dollar";
                    }
                    else if (count == 0) {
                        auto y = lower_Units[num[0] - '0'];

                        if (num[1] == 0)
                            finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                        else {

                            if (num[2] == '0')
                                finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                            else {
                                num.erase(0, 1);

                                if (num == "11")
                                    finale += y + " hundred " + lower_Tens[11] + " dollars";
                                else if (num == "12")
                                    finale += y + " hundred " + lower_Tens[12] + " dollars";
                                else
                                    finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                            }
                        }
                    }
                    break;
                }
                case 1: {
                    // making thousands

                    // making tens

                    if (num[0] == 1)
                        switch (num[1]) {
                        case 1:
                            finale += upper_Tens[11] + " thousand ";
                        case 2:
                            finale += upper_Tens[12] + " thousand ";
                        }
                    else {

                        if (num[1] == '0')
                            finale += upper_Tens[num[0] - '0'] + " thousand ";
                        else
                            finale += upper_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " thousand ";
                    }


                    num.erase(0, 2);

                    // making hundreds
                    int count = 0;

                    for (int i = 0; i < num.length(); i++) {

                        if (num[i] == '0') {
                            count++;
                            continue;
                        }
                    }

                    if (count == 1) {

                        if (num == "11")
                            finale += lower_Tens[11];
                        else
                            finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                    }
                    else if (count == 2) {
                        auto y = lower_Units[num[0] - '0'];
                        finale += y + " dollar";
                    }
                    else if (count == 0) {
                        auto y = lower_Units[num[0] - '0'];

                        if (num[1] == 0)
                            finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                        else {

                            if (num[2] == '0')
                                finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                            else {
                                num.erase(0, 1);

                                if (num == "11")
                                    finale += y + " hundred " + lower_Tens[11] + " dollars";
                                else if (num == "12")
                                    finale += y + " hundred " + lower_Tens[12] + " dollars";
                                else
                                    finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                            }
                        }
                    }
                    break;
                }
                case 2: {
                    // making thousands

                    finale += upper_Units[num[0] - '0'] + " thousand ";


                    num.erase(0, 1);

                    // making hundreds
                    int count = 0;

                    for (int i = 0; i < num.length(); i++) {

                        if (num[i] == '0') {
                            count++;
                            continue;
                        }
                    }

                    if (count == 1) {

                        if (num == "11")
                            finale += lower_Tens[11];
                        else
                            finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                    }
                    else if (count == 2) {
                        auto y = lower_Units[num[0] - '0'];
                        finale += y + " dollar";
                    }
                    else if (count == 0) {
                        auto y = lower_Units[num[0] - '0'];

                        if (num[1] == 0)
                            finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                        else {

                            if (num[2] == '0')
                                finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                            else {
                                num.erase(0, 1);

                                if (num == "11")
                                    finale += y + " hundred " + lower_Tens[11] + " dollars";
                                else if (num == "12")
                                    finale += y + " hundred " + lower_Tens[12] + " dollars";
                                else
                                    finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                            }
                        }
                    }
                    break;
                }
                case 3: {

                    // making hundreds

                    auto y = upper_Units[num[0] - '0'];

                    if (num[1] == 0)
                        finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                    else {

                        if (num[2] == '0')
                            finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                        else {
                            num.erase(0, 1);

                            if (num == "11")
                                finale += y + " hundred " + lower_Tens[11] + " dollars";
                            else if (num == "12")
                                finale += y + " hundred " + lower_Tens[12] + " dollars";
                            else
                                finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                        }
                    }
                    break;
                }
                case 4: {
                    if (num[1] == '0')
                        finale += upper_Tens[num[0] - '0'];
                    else
                        if (num[0] == 1)
                            switch (num[1]) {
                            case 1:
                                finale += upper_Tens[11] + " dollars";
                            case 2:
                                finale += upper_Tens[12] + " dollars";
                            }
                        else
                            finale += upper_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";
                    break;
                }
                case 5: {
                    auto y = upper_Units[std::stoi(num)];
                    finale += y + " dollar";
                    break;
                }
                case 6: {
                    finale += upper_Units[0] + " dollars.";
                    break;
                }
                }
                break;
            }
            case 5: {
                int count = 0;

                for (int i = 0; i < num.length(); i++) {

                    if (num[i] == '0') {
                        num.erase(0, 1);
                        count++;
                        continue;
                    }
                }
                
                switch (count) {
                case 0: {
                    // making thousands

                    // making tens

                    if (num[0] == 1)
                        switch (num[1]) {
                        case 1:
                            finale += upper_Tens[11] + " thousand ";
                        case 2:
                            finale += upper_Tens[12] + " thousand ";
                        }
                    else {

                        if (num[1] == '0')
                            finale += upper_Tens[num[0] - '0'] + " thousand ";
                        else
                            finale += upper_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " thousand ";
                    }


                    num.erase(0, 2);

                    // making hundreds
                    int count = 0;

                    for (int i = 0; i < num.length(); i++) {

                        if (num[i] == '0') {
                            count++;
                            continue;
                        }
                    }

                    if (count == 1) {

                        if (num == "11")
                            finale += lower_Tens[11];
                        else
                            finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                    }
                    else if (count == 2) {
                        auto y = lower_Units[num[0] - '0'];
                        finale += y + " dollar";
                    }
                    else if (count == 0) {
                        auto y = lower_Units[num[0] - '0'];

                        if (num[1] == 0)
                            finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                        else {

                            if (num[2] == '0')
                                finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                            else {
                                num.erase(0, 1);

                                if (num == "11")
                                    finale += y + " hundred " + lower_Tens[11] + " dollars";
                                else if (num == "12")
                                    finale += y + " hundred " + lower_Tens[12] + " dollars";
                                else
                                    finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                            }
                        }
                    }
                    break;
                }
                case 1: {
                    // making thousands

                    finale += upper_Units[num[0] - '0'] + " thousand ";


                    num.erase(0, 1);

                    // making hundreds
                    int count = 0;

                    for (int i = 0; i < num.length(); i++) {

                        if (num[i] == '0') {
                            count++;
                            continue;
                        }
                    }

                    if (count == 1) {

                        if (num == "11")
                            finale += lower_Tens[11];
                        else
                            finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                    }
                    else if (count == 2) {
                        auto y = lower_Units[num[0] - '0'];
                        finale += y + " dollar";
                    }
                    else if (count == 0) {
                        auto y = lower_Units[num[0] - '0'];

                        if (num[1] == 0)
                            finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                        else {

                            if (num[2] == '0')
                                finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                            else {
                                num.erase(0, 1);

                                if (num == "11")
                                    finale += y + " hundred " + lower_Tens[11] + " dollars";
                                else if (num == "12")
                                    finale += y + " hundred " + lower_Tens[12] + " dollars";
                                else
                                    finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                            }
                        }
                    }
                    break;
                }
                case 2: {
                    // making thousands

                    finale += upper_Units[num[0] - '0'] + " thousand ";


                    num.erase(0, 1);

                    // making hundreds
                    int count = 0;

                    for (int i = 0; i < num.length(); i++) {

                        if (num[i] == '0') {
                            count++;
                            continue;
                        }
                    }

                    if (count == 1) {

                        if (num == "11")
                            finale += lower_Tens[11];
                        else
                            finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                    }
                    else if (count == 2) {
                        auto y = lower_Units[num[0] - '0'];
                        finale += y + " dollar";
                    }
                    else if (count == 0) {
                        auto y = lower_Units[num[0] - '0'];

                        if (num[1] == 0)
                            finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                        else {

                            if (num[2] == '0')
                                finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                            else {
                                num.erase(0, 1);

                                if (num == "11")
                                    finale += y + " hundred " + lower_Tens[11] + " dollars";
                                else if (num == "12")
                                    finale += y + " hundred " + lower_Tens[12] + " dollars";
                                else
                                    finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                            }
                        }
                    }
                    break;
                }
                case 3: {
                    if (num[1] == '0')
                        finale += upper_Tens[num[0] - '0'];
                    else
                        if (num[0] == 1)
                            switch (num[1]) {
                            case 1:
                                finale += upper_Tens[11] + " dollars";
                            case 2:
                                finale += upper_Tens[12] + " dollars";
                            }
                        else
                            finale += upper_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";
                    break;
                }
                case 4: {
                    auto y = upper_Units[std::stoi(num)];
                    finale += y + " dollar";
                    break;
                }
                case 5: {
                    finale += upper_Units[0] + " dollars.";
                    break;
                }
                }
                break;
            }
            case 4: {
                int count = 0;

                for (int i = 0; i < num.length(); i++) {

                    if (num[i] == '0') {
                        num.erase(0, 1);
                        count++;
                        continue;
                    }
                }

                switch (count) {
                case 0: {
                    // making thousands

                    finale += upper_Units[num[0] - '0'] + " thousand ";


                    num.erase(0, 1);

                    // making hundreds
                    int count = 0;

                    for (int i = 0; i < num.length(); i++) {

                        if (num[i] == '0') {
                            count++;
                            continue;
                        }
                    }

                    if (count == 1) {

                        if (num == "11")
                            finale += lower_Tens[11];
                        else
                            finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                    }
                    else if (count == 2) {
                        auto y = lower_Units[num[0] - '0'];
                        finale += y + " dollar";
                    }
                    else if (count == 0) {
                        auto y = lower_Units[num[0] - '0'];

                        if (num[1] == 0)
                            finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                        else {

                            if (num[2] == '0')
                                finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                            else {
                                num.erase(0, 1);

                                if (num == "11")
                                    finale += y + " hundred " + lower_Tens[11] + " dollars";
                                else if (num == "12")
                                    finale += y + " hundred " + lower_Tens[12] + " dollars";
                                else
                                    finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                            }
                        }
                    }
                    break;
                }
                case 1: {
                    // making thousands

                    finale += upper_Units[num[0] - '0'] + " thousand ";


                    num.erase(0, 1);

                    // making hundreds
                    int count = 0;

                    for (int i = 0; i < num.length(); i++) {

                        if (num[i] == '0') {
                            count++;
                            continue;
                        }
                    }

                    if (count == 1) {

                        if (num == "11")
                            finale += lower_Tens[11];
                        else
                            finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                    }
                    else if (count == 2) {
                        auto y = lower_Units[num[0] - '0'];
                        finale += y + " dollar";
                    }
                    else if (count == 0) {
                        auto y = lower_Units[num[0] - '0'];

                        if (num[1] == 0)
                            finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                        else {

                            if (num[2] == '0')
                                finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                            else {
                                num.erase(0, 1);

                                if (num == "11")
                                    finale += y + " hundred " + lower_Tens[11] + " dollars";
                                else if (num == "12")
                                    finale += y + " hundred " + lower_Tens[12] + " dollars";
                                else
                                    finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                            }
                        }
                    }
                    break;
                }
                case 2: {
                    if (num[1] == '0')
                        finale += upper_Tens[num[0] - '0'];
                    else
                        if (num[0] == 1)
                            switch (num[1]) {
                            case 1:
                                finale += upper_Tens[11] + " dollars";
                            case 2:
                                finale += upper_Tens[12] + " dollars";
                            }
                        else
                            finale += upper_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";
                    break;
                }
                case 3: {
                    auto y = upper_Units[std::stoi(num)];
                    finale += y + " dollar";
                    break;
                }
                case 4: {
                    finale += upper_Units[0] + " dollars.";
                    break;
                }
                }
                break;
            }
            }
        }
        else if (x >= 1000000 && x <= 999999999) {
            switch (num.length()) {
            case 9: {
                int count = 0;

                for (int i = 0; i < num.length(); i++) {

                    if (num[0] == '0') {
                        num.erase(0, 1);
                        count++;
                        continue;
                    }
                }

                switch (count) {
                case 0: {
                    // making millions

                    finale += upper_Units[num[0] - '0'] + " hundred ";
                    num.erase(0, 1);

                    if (num[1] == '0') {
                        finale += lower_Tens[num[0] - '0'] + " million ";
                    }
                    else {
                        switch (num[1]) {
                        case 1:
                            finale += lower_Tens[11] + " million ";
                        case 2:
                            finale += lower_Tens[12] + " million ";
                        default: {
                            finale += lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " million ";
                        }
                        }
                    }

                    num.erase(0, 2);

                    int count = 0;

                    for (int i = 0; i < num.length(); i++) {

                        if (num[i] == '0') {
                            num.erase(0, 1);
                            count++;
                            continue;
                        }
                    }

                    switch (count) {
                    case 0: {
                        // making thousands

                        // making hundreds
                        finale += lower_Units[num[0] - '0'] + " hundred ";
                        num.erase(0, 1);

                        // making tens
                        if (num[0] == '0') {
                            if (num[1] != '0')
                                finale += lower_Units[num[1] - '0'] + " thousand ";
                            else
                                finale += " thousand";
                        }
                        else {

                            if (num[0] == 1)
                                switch (num[1]) {
                                case 1:
                                    finale += lower_Tens[11] + " thousand ";
                                case 2:
                                    finale += lower_Tens[12] + " thousand ";
                                }
                            else {

                                if (num[1] == '0')
                                    finale += lower_Tens[num[0] - '0'] + " thousand ";
                                else
                                    finale += lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " thousand ";
                            }
                        }

                        num.erase(0, 2);

                        // making hundreds
                        int count = 0;

                        for (int i = 0; i < num.length(); i++) {

                            if (num[i] == '0') {
                                count++;
                                continue;
                            }
                        }

                        if (count == 1) {

                            if (num == "11")
                                finale += lower_Tens[11];
                            else
                                finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                        }
                        else if (count == 2) {
                            auto y = lower_Units[num[0] - '0'];
                            finale += y + " dollar";
                        }
                        else if (count == 0) {
                            auto y = lower_Units[num[0] - '0'];

                            if (num[1] == 0)
                                finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                            else {

                                if (num[2] == '0')
                                    finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                                else {
                                    num.erase(0, 1);

                                    if (num == "11")
                                        finale += y + " hundred " + lower_Tens[11] + " dollars";
                                    else if (num == "12")
                                        finale += y + " hundred " + lower_Tens[12] + " dollars";
                                    else
                                        finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                                }
                            }
                        }
                        break;
                    }
                    case 1: {
                        // making thousands

                        // making tens

                        if (num[0] == 1)
                            switch (num[1]) {
                            case 1:
                                finale += lower_Tens[11] + " thousand ";
                            case 2:
                                finale += lower_Tens[12] + " thousand ";
                            }
                        else {

                            if (num[1] == '0')
                                finale += lower_Tens[num[0] - '0'] + " thousand ";
                            else
                                finale += lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " thousand ";
                        }


                        num.erase(0, 2);

                        // making hundreds
                        int count = 0;

                        for (int i = 0; i < num.length(); i++) {

                            if (num[i] == '0') {
                                count++;
                                continue;
                            }
                        }

                        if (count == 1) {

                            if (num == "11")
                                finale += lower_Tens[11];
                            else
                                finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                        }
                        else if (count == 2) {
                            auto y = lower_Units[num[0] - '0'];
                            finale += y + " dollar";
                        }
                        else if (count == 0) {
                            auto y = lower_Units[num[0] - '0'];

                            if (num[1] == 0)
                                finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                            else {

                                if (num[2] == '0')
                                    finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                                else {
                                    num.erase(0, 1);

                                    if (num == "11")
                                        finale += y + " hundred " + lower_Tens[11] + " dollars";
                                    else if (num == "12")
                                        finale += y + " hundred " + lower_Tens[12] + " dollars";
                                    else
                                        finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                                }
                            }
                        }
                        break;
                    }
                    case 2: {
                        // making thousands

                        finale += lower_Units[num[0] - '0'] + " thousand ";


                        num.erase(0, 1);

                        // making hundreds
                        int count = 0;

                        for (int i = 0; i < num.length(); i++) {

                            if (num[i] == '0') {
                                count++;
                                continue;
                            }
                        }

                        if (count == 1) {

                            if (num == "11")
                                finale += lower_Tens[11];
                            else
                                finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                        }
                        else if (count == 2) {
                            auto y = lower_Units[num[0] - '0'];
                            finale += y + " dollar";
                        }
                        else if (count == 0) {
                            auto y = lower_Units[num[0] - '0'];

                            if (num[1] == 0)
                                finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                            else {

                                if (num[2] == '0')
                                    finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                                else {
                                    num.erase(0, 1);

                                    if (num == "11")
                                        finale += y + " hundred " + lower_Tens[11] + " dollars";
                                    else if (num == "12")
                                        finale += y + " hundred " + lower_Tens[12] + " dollars";
                                    else
                                        finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                                }
                            }
                        }
                        break;
                    }
                    case 3: {

                        // making hundreds

                        auto y = lower_Units[num[0] - '0'];

                        if (num[1] == 0)
                            finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                        else {

                            if (num[2] == '0')
                                finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                            else {
                                num.erase(0, 1);

                                if (num == "11")
                                    finale += y + " hundred " + lower_Tens[11] + " dollars";
                                else if (num == "12")
                                    finale += y + " hundred " + lower_Tens[12] + " dollars";
                                else
                                    finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                            }
                        }
                        break;
                    }
                    case 4: {
                        if (num[1] == '0')
                            finale += lower_Tens[num[0] - '0'];
                        else
                            if (num[0] == 1)
                                switch (num[1]) {
                                case 1:
                                    finale += lower_Tens[11] + " dollars";
                                case 2:
                                    finale += lower_Tens[12] + " dollars";
                                }
                            else
                                finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";
                        break;
                    }
                    case 5: {
                        auto y = lower_Units[std::stoi(num)];
                        finale += y + " dollar";
                        break;
                    }
                    case 6: {
                        finale += lower_Units[0] + " dollars.";
                        break;
                    }
                    }
                   
                    break;
                }
                case 1: {
                    
                        // making millions

                        if (num[1] == '0') {
                            finale += upper_Tens[num[0] - '0'] + " million ";
                        }
                        else {
                            switch (num[1]) {
                            case 1:
                                finale += upper_Tens[11] + " million ";
                            case 2:
                                finale += upper_Tens[12] + " million ";
                            default: {
                                finale += upper_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " million ";
                            }
                            }
                        }

                        num.erase(0, 2);

                        int count = 0;

                        for (int i = 0; i < num.length(); i++) {

                            if (num[i] == '0') {
                                num.erase(0, 1);
                                count++;
                                continue;
                            }
                        }

                        switch (count) {
                        case 0: {
                            // making thousands

                            // making hundreds
                            finale += lower_Tens[num[0] - '0'] + " hundred ";
                            num.erase(0, 1);

                            // making tens
                            if (num[0] == '0') {
                                if (num[1] != '0')
                                    finale += lower_Units[num[1] - '0'] + " thousand ";
                                else
                                    finale += " thousand";
                            }
                            else {

                                if (num[0] == 1)
                                    switch (num[1]) {
                                    case 1:
                                        finale += lower_Tens[11] + " thousand ";
                                    case 2:
                                        finale += lower_Tens[12] + " thousand ";
                                    }
                                else {

                                    if (num[1] == '0')
                                        finale += lower_Tens[num[0] - '0'] + " thousand ";
                                    else
                                        finale += lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " thousand ";
                                }
                            }

                            num.erase(0, 2);

                            // making hundreds
                            int count = 0;

                            for (int i = 0; i < num.length(); i++) {

                                if (num[i] == '0') {
                                    count++;
                                    continue;
                                }
                            }

                            if (count == 1) {

                                if (num == "11")
                                    finale += lower_Tens[11];
                                else
                                    finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                            }
                            else if (count == 2) {
                                auto y = lower_Units[num[0] - '0'];
                                finale += y + " dollar";
                            }
                            else if (count == 0) {
                                auto y = lower_Units[num[0] - '0'];

                                if (num[1] == 0)
                                    finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                                else {

                                    if (num[2] == '0')
                                        finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                                    else {
                                        num.erase(0, 1);

                                        if (num == "11")
                                            finale += y + " hundred " + lower_Tens[11] + " dollars";
                                        else if (num == "12")
                                            finale += y + " hundred " + lower_Tens[12] + " dollars";
                                        else
                                            finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                                    }
                                }
                            }
                            break;
                        }
                        case 1: {
                            // making thousands

                            // making tens

                            if (num[0] == 1)
                                switch (num[1]) {
                                case 1:
                                    finale += lower_Tens[11] + " thousand ";
                                case 2:
                                    finale += lower_Tens[12] + " thousand ";
                                }
                            else {

                                if (num[1] == '0')
                                    finale += lower_Tens[num[0] - '0'] + " thousand ";
                                else
                                    finale += lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " thousand ";
                            }


                            num.erase(0, 2);

                            // making hundreds
                            int count = 0;

                            for (int i = 0; i < num.length(); i++) {

                                if (num[i] == '0') {
                                    count++;
                                    continue;
                                }
                            }

                            if (count == 1) {

                                if (num == "11")
                                    finale += lower_Tens[11];
                                else
                                    finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                            }
                            else if (count == 2) {
                                auto y = lower_Units[num[0] - '0'];
                                finale += y + " dollar";
                            }
                            else if (count == 0) {
                                auto y = lower_Units[num[0] - '0'];

                                if (num[1] == 0)
                                    finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                                else {

                                    if (num[2] == '0')
                                        finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                                    else {
                                        num.erase(0, 1);

                                        if (num == "11")
                                            finale += y + " hundred " + lower_Tens[11] + " dollars";
                                        else if (num == "12")
                                            finale += y + " hundred " + lower_Tens[12] + " dollars";
                                        else
                                            finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                                    }
                                }
                            }
                            break;
                        }
                        case 2: {
                            // making thousands

                            finale += lower_Units[num[0] - '0'] + " thousand ";


                            num.erase(0, 1);

                            // making hundreds
                            int count = 0;

                            for (int i = 0; i < num.length(); i++) {

                                if (num[i] == '0') {
                                    count++;
                                    continue;
                                }
                            }

                            if (count == 1) {

                                if (num == "11")
                                    finale += lower_Tens[11];
                                else
                                    finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                            }
                            else if (count == 2) {
                                auto y = lower_Units[num[0] - '0'];
                                finale += y + " dollar";
                            }
                            else if (count == 0) {
                                auto y = lower_Units[num[0] - '0'];

                                if (num[1] == 0)
                                    finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                                else {

                                    if (num[2] == '0')
                                        finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                                    else {
                                        num.erase(0, 1);

                                        if (num == "11")
                                            finale += y + " hundred " + lower_Tens[11] + " dollars";
                                        else if (num == "12")
                                            finale += y + " hundred " + lower_Tens[12] + " dollars";
                                        else
                                            finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                                    }
                                }
                            }
                            break;
                        }
                        case 3: {

                            // making hundreds

                            auto y = lower_Units[num[0] - '0'];

                            if (num[1] == 0)
                                finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                            else {

                                if (num[2] == '0')
                                    finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                                else {
                                    num.erase(0, 1);

                                    if (num == "11")
                                        finale += y + " hundred " + lower_Tens[11] + " dollars";
                                    else if (num == "12")
                                        finale += y + " hundred " + lower_Tens[12] + " dollars";
                                    else
                                        finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                                }
                            }
                            break;
                        }
                        case 4: {
                            if (num[1] == '0')
                                finale += lower_Tens[num[0] - '0'];
                            else
                                if (num[0] == 1)
                                    switch (num[1]) {
                                    case 1:
                                        finale += lower_Tens[11] + " dollars";
                                    case 2:
                                        finale += lower_Tens[12] + " dollars";
                                    }
                                else
                                    finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";
                            break;
                        }
                        case 5: {
                            auto y = lower_Units[std::stoi(num)];
                            finale += y + " dollar";
                            break;
                        }
                        case 6: {
                            finale += lower_Units[0] + " dollars.";
                            break;
                        }
                        }

                        break;
                }
                case 2: {

                    // making millions

                    finale += upper_Units[num[0] - '0'] + " million ";

                    num.erase(0, 1);

                    int count = 0;

                    for (int i = 0; i < num.length(); i++) {

                        if (num[i] == '0') {
                            num.erase(0, 1);
                            count++;
                            continue;
                        }
                    }

                    switch (count) {
                    case 0: {
                        // making thousands

                        // making hundreds
                        finale += lower_Tens[num[0] - '0'] + " hundred ";
                        num.erase(0, 1);

                        // making tens
                        if (num[0] == '0') {
                            if (num[1] != '0')
                                finale += lower_Units[num[1] - '0'] + " thousand ";
                            else
                                finale += " thousand";
                        }
                        else {

                            if (num[0] == 1)
                                switch (num[1]) {
                                case 1:
                                    finale += lower_Tens[11] + " thousand ";
                                case 2:
                                    finale += lower_Tens[12] + " thousand ";
                                }
                            else {

                                if (num[1] == '0')
                                    finale += lower_Tens[num[0] - '0'] + " thousand ";
                                else
                                    finale += lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " thousand ";
                            }
                        }

                        num.erase(0, 2);

                        // making hundreds
                        int count = 0;

                        for (int i = 0; i < num.length(); i++) {

                            if (num[i] == '0') {
                                count++;
                                continue;
                            }
                        }

                        if (count == 1) {

                            if (num == "11")
                                finale += lower_Tens[11];
                            else
                                finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                        }
                        else if (count == 2) {
                            auto y = lower_Units[num[0] - '0'];
                            finale += y + " dollar";
                        }
                        else if (count == 0) {
                            auto y = lower_Units[num[0] - '0'];

                            if (num[1] == 0)
                                finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                            else {

                                if (num[2] == '0')
                                    finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                                else {
                                    num.erase(0, 1);

                                    if (num == "11")
                                        finale += y + " hundred " + lower_Tens[11] + " dollars";
                                    else if (num == "12")
                                        finale += y + " hundred " + lower_Tens[12] + " dollars";
                                    else
                                        finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                                }
                            }
                        }
                        break;
                    }
                    case 1: {
                        // making thousands

                        // making tens

                        if (num[0] == 1)
                            switch (num[1]) {
                            case 1:
                                finale += lower_Tens[11] + " thousand ";
                            case 2:
                                finale += lower_Tens[12] + " thousand ";
                            }
                        else {

                            if (num[1] == '0')
                                finale += lower_Tens[num[0] - '0'] + " thousand ";
                            else
                                finale += lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " thousand ";
                        }


                        num.erase(0, 2);

                        // making hundreds
                        int count = 0;

                        for (int i = 0; i < num.length(); i++) {

                            if (num[i] == '0') {
                                count++;
                                continue;
                            }
                        }

                        if (count == 1) {

                            if (num == "11")
                                finale += lower_Tens[11];
                            else
                                finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                        }
                        else if (count == 2) {
                            auto y = lower_Units[num[0] - '0'];
                            finale += y + " dollar";
                        }
                        else if (count == 0) {
                            auto y = lower_Units[num[0] - '0'];

                            if (num[1] == 0)
                                finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                            else {

                                if (num[2] == '0')
                                    finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                                else {
                                    num.erase(0, 1);

                                    if (num == "11")
                                        finale += y + " hundred " + lower_Tens[11] + " dollars";
                                    else if (num == "12")
                                        finale += y + " hundred " + lower_Tens[12] + " dollars";
                                    else
                                        finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                                }
                            }
                        }
                        break;
                    }
                    case 2: {
                        // making thousands

                        finale += lower_Units[num[0] - '0'] + " thousand ";


                        num.erase(0, 1);

                        // making hundreds
                        int count = 0;

                        for (int i = 0; i < num.length(); i++) {

                            if (num[i] == '0') {
                                count++;
                                continue;
                            }
                        }

                        if (count == 1) {

                            if (num == "11")
                                finale += lower_Tens[11];
                            else
                                finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                        }
                        else if (count == 2) {
                            auto y = lower_Units[num[0] - '0'];
                            finale += y + " dollar";
                        }
                        else if (count == 0) {
                            auto y = lower_Units[num[0] - '0'];

                            if (num[1] == 0)
                                finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                            else {

                                if (num[2] == '0')
                                    finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                                else {
                                    num.erase(0, 1);

                                    if (num == "11")
                                        finale += y + " hundred " + lower_Tens[11] + " dollars";
                                    else if (num == "12")
                                        finale += y + " hundred " + lower_Tens[12] + " dollars";
                                    else
                                        finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                                }
                            }
                        }
                        break;
                    }
                    case 3: {

                        // making hundreds

                        auto y = lower_Units[num[0] - '0'];

                        if (num[1] == 0)
                            finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                        else {

                            if (num[2] == '0')
                                finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                            else {
                                num.erase(0, 1);

                                if (num == "11")
                                    finale += y + " hundred " + lower_Tens[11] + " dollars";
                                else if (num == "12")
                                    finale += y + " hundred " + lower_Tens[12] + " dollars";
                                else
                                    finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                            }
                        }
                        break;
                    }
                    case 4: {
                        if (num[1] == '0')
                            finale += lower_Tens[num[0] - '0'];
                        else
                            if (num[0] == 1)
                                switch (num[1]) {
                                case 1:
                                    finale += lower_Tens[11] + " dollars";
                                case 2:
                                    finale += lower_Tens[12] + " dollars";
                                }
                            else
                                finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";
                        break;
                    }
                    case 5: {
                        auto y = lower_Units[std::stoi(num)];
                        finale += y + " dollar";
                        break;
                    }
                    case 6: {
                        finale += lower_Units[0] + " dollars.";
                        break;
                    }
                    }

                    break;
                }
                case 3: {
                    // making thousands

                    // making hundreds
                    finale += upper_Units[num[0] - '0'] + " hundred ";
                    num.erase(0, 1);

                    // making tens
                    if (num[0] == '0') {
                        if (num[1] != '0')
                            finale += lower_Units[num[1] - '0'] + " thousand ";
                        else
                            finale += " thousand";
                    }
                    else {

                        if (num[0] == 1)
                            switch (num[1]) {
                            case 1:
                                finale += lower_Tens[11] + " thousand ";
                            case 2:
                                finale += lower_Tens[12] + " thousand ";
                            }
                        else {

                            if (num[1] == '0')
                                finale += lower_Tens[num[0] - '0'] + " thousand ";
                            else
                                finale += lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " thousand ";
                        }
                    }

                    num.erase(0, 2);

                    // making hundreds
                    int count = 0;

                    for (int i = 0; i < num.length(); i++) {

                        if (num[i] == '0') {
                            count++;
                            continue;
                        }
                    }

                    if (count == 1) {

                        if (num == "11")
                            finale += lower_Tens[11];
                        else
                            finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                    }
                    else if (count == 2) {
                        auto y = lower_Units[num[0] - '0'];
                        finale += y + " dollar";
                    }
                    else if (count == 0) {
                        auto y = lower_Units[num[0] - '0'];

                        if (num[1] == 0)
                            finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                        else {

                            if (num[2] == '0')
                                finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                            else {
                                num.erase(0, 1);

                                if (num == "11")
                                    finale += y + " hundred " + lower_Tens[11] + " dollars";
                                else if (num == "12")
                                    finale += y + " hundred " + lower_Tens[12] + " dollars";
                                else
                                    finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                            }
                        }
                    }
                    break;
                }
                case 4: {
                    // making thousands

                    // making tens

                    if (num[0] == 1)
                        switch (num[1]) {
                        case 1:
                            finale += upper_Tens[11] + " thousand ";
                        case 2:
                            finale += upper_Tens[12] + " thousand ";
                        }
                    else {

                        if (num[1] == '0')
                            finale += upper_Tens[num[0] - '0'] + " thousand ";
                        else
                            finale += upper_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " thousand ";
                    }


                    num.erase(0, 2);

                    // making hundreds
                    int count = 0;

                    for (int i = 0; i < num.length(); i++) {

                        if (num[i] == '0') {
                            count++;
                            continue;
                        }
                    }

                    if (count == 1) {

                        if (num == "11")
                            finale += lower_Tens[11];
                        else
                            finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                    }
                    else if (count == 2) {
                        auto y = lower_Units[num[0] - '0'];
                        finale += y + " dollar";
                    }
                    else if (count == 0) {
                        auto y = lower_Units[num[0] - '0'];

                        if (num[1] == 0)
                            finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                        else {

                            if (num[2] == '0')
                                finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                            else {
                                num.erase(0, 1);

                                if (num == "11")
                                    finale += y + " hundred " + lower_Tens[11] + " dollars";
                                else if (num == "12")
                                    finale += y + " hundred " + lower_Tens[12] + " dollars";
                                else
                                    finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                            }
                        }
                    }
                    break;
                }
                case 5: {
                    // making thousands

                    finale += upper_Units[num[0] - '0'] + " thousand ";


                    num.erase(0, 1);

                    // making hundreds
                    int count = 0;

                    for (int i = 0; i < num.length(); i++) {

                        if (num[i] == '0') {
                            count++;
                            continue;
                        }
                    }

                    if (count == 1) {

                        if (num == "11")
                            finale += lower_Tens[11];
                        else
                            finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                    }
                    else if (count == 2) {
                        auto y = lower_Units[num[0] - '0'];
                        finale += y + " dollar";
                    }
                    else if (count == 0) {
                        auto y = lower_Units[num[0] - '0'];

                        if (num[1] == 0)
                            finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                        else {

                            if (num[2] == '0')
                                finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                            else {
                                num.erase(0, 1);

                                if (num == "11")
                                    finale += y + " hundred " + lower_Tens[11] + " dollars";
                                else if (num == "12")
                                    finale += y + " hundred " + lower_Tens[12] + " dollars";
                                else
                                    finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                            }
                        }
                    }
                    break;
                }
                case 6: {

                    // making hundreds

                    auto y = upper_Units[num[0] - '0'];

                    if (num[1] == 0)
                        finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                    else {

                        if (num[2] == '0')
                            finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                        else {
                            num.erase(0, 1);

                            if (num == "11")
                                finale += y + " hundred " + lower_Tens[11] + " dollars";
                            else if (num == "12")
                                finale += y + " hundred " + lower_Tens[12] + " dollars";
                            else
                                finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                        }
                    }
                    break;
                }
                case 7: {
                    if (num[1] == '0')
                        finale += upper_Tens[num[0] - '0'];
                    else
                        if (num[0] == 1)
                            switch (num[1]) {
                            case 1:
                                finale += upper_Tens[11] + " dollars";
                            case 2:
                                finale += upper_Tens[12] + " dollars";
                            }
                        else
                            finale += upper_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";
                    break;
                }
                case 8: {
                    auto y = upper_Units[std::stoi(num)];
                    finale += y + " dollar";
                    break;
                }
                case 9: {
                    finale += upper_Units[0] + " dollars.";
                    break;
                }
                }
                break;
            }
            case 8: {
                int count = 0;

                for (int i = 0; i < num.length(); i++) {

                    if (num[0] == '0') {
                        num.erase(0, 1);
                        count++;
                        continue;
                    }
                }

                switch (count) {
                case 0: {

                    // making millions

                    if (num[1] == '0') {
                        finale += upper_Tens[num[0] - '0'] + " million ";
                    }
                    else {
                        switch (num[1]) {
                        case 1:
                            finale += upper_Tens[11] + " million ";
                        case 2:
                            finale += upper_Tens[12] + " million ";
                        default: {
                            finale += upper_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " million ";
                        }
                        }
                    }

                    num.erase(0, 2);

                    int count = 0;

                    for (int i = 0; i < num.length(); i++) {

                        if (num[i] == '0') {
                            num.erase(0, 1);
                            count++;
                            continue;
                        }
                    }

                    switch (count) {
                    case 0: {
                        // making thousands

                        // making hundreds
                        finale += lower_Tens[num[0] - '0'] + " hundred ";
                        num.erase(0, 1);

                        // making tens
                        if (num[0] == '0') {
                            if (num[1] != '0')
                                finale += lower_Units[num[1] - '0'] + " thousand ";
                            else
                                finale += " thousand";
                        }
                        else {

                            if (num[0] == 1)
                                switch (num[1]) {
                                case 1:
                                    finale += lower_Tens[11] + " thousand ";
                                case 2:
                                    finale += lower_Tens[12] + " thousand ";
                                }
                            else {

                                if (num[1] == '0')
                                    finale += lower_Tens[num[0] - '0'] + " thousand ";
                                else
                                    finale += lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " thousand ";
                            }
                        }

                        num.erase(0, 2);

                        // making hundreds
                        int count = 0;

                        for (int i = 0; i < num.length(); i++) {

                            if (num[i] == '0') {
                                count++;
                                continue;
                            }
                        }

                        if (count == 1) {

                            if (num == "11")
                                finale += lower_Tens[11];
                            else
                                finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                        }
                        else if (count == 2) {
                            auto y = lower_Units[num[0] - '0'];
                            finale += y + " dollar";
                        }
                        else if (count == 0) {
                            auto y = lower_Units[num[0] - '0'];

                            if (num[1] == 0)
                                finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                            else {

                                if (num[2] == '0')
                                    finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                                else {
                                    num.erase(0, 1);

                                    if (num == "11")
                                        finale += y + " hundred " + lower_Tens[11] + " dollars";
                                    else if (num == "12")
                                        finale += y + " hundred " + lower_Tens[12] + " dollars";
                                    else
                                        finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                                }
                            }
                        }
                        break;
                    }
                    case 1: {
                        // making thousands

                        // making tens

                        if (num[0] == 1)
                            switch (num[1]) {
                            case 1:
                                finale += lower_Tens[11] + " thousand ";
                            case 2:
                                finale += lower_Tens[12] + " thousand ";
                            }
                        else {

                            if (num[1] == '0')
                                finale += lower_Tens[num[0] - '0'] + " thousand ";
                            else
                                finale += lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " thousand ";
                        }


                        num.erase(0, 2);

                        // making hundreds
                        int count = 0;

                        for (int i = 0; i < num.length(); i++) {

                            if (num[i] == '0') {
                                count++;
                                continue;
                            }
                        }

                        if (count == 1) {

                            if (num == "11")
                                finale += lower_Tens[11];
                            else
                                finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                        }
                        else if (count == 2) {
                            auto y = lower_Units[num[0] - '0'];
                            finale += y + " dollar";
                        }
                        else if (count == 0) {
                            auto y = lower_Units[num[0] - '0'];

                            if (num[1] == 0)
                                finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                            else {

                                if (num[2] == '0')
                                    finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                                else {
                                    num.erase(0, 1);

                                    if (num == "11")
                                        finale += y + " hundred " + lower_Tens[11] + " dollars";
                                    else if (num == "12")
                                        finale += y + " hundred " + lower_Tens[12] + " dollars";
                                    else
                                        finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                                }
                            }
                        }
                        break;
                    }
                    case 2: {
                        // making thousands

                        finale += lower_Units[num[0] - '0'] + " thousand ";


                        num.erase(0, 1);

                        // making hundreds
                        int count = 0;

                        for (int i = 0; i < num.length(); i++) {

                            if (num[i] == '0') {
                                count++;
                                continue;
                            }
                        }

                        if (count == 1) {

                            if (num == "11")
                                finale += lower_Tens[11];
                            else
                                finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                        }
                        else if (count == 2) {
                            auto y = lower_Units[num[0] - '0'];
                            finale += y + " dollar";
                        }
                        else if (count == 0) {
                            auto y = lower_Units[num[0] - '0'];

                            if (num[1] == 0)
                                finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                            else {

                                if (num[2] == '0')
                                    finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                                else {
                                    num.erase(0, 1);

                                    if (num == "11")
                                        finale += y + " hundred " + lower_Tens[11] + " dollars";
                                    else if (num == "12")
                                        finale += y + " hundred " + lower_Tens[12] + " dollars";
                                    else
                                        finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                                }
                            }
                        }
                        break;
                    }
                    case 3: {

                        // making hundreds

                        auto y = lower_Units[num[0] - '0'];

                        if (num[1] == 0)
                            finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                        else {

                            if (num[2] == '0')
                                finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                            else {
                                num.erase(0, 1);

                                if (num == "11")
                                    finale += y + " hundred " + lower_Tens[11] + " dollars";
                                else if (num == "12")
                                    finale += y + " hundred " + lower_Tens[12] + " dollars";
                                else
                                    finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                            }
                        }
                        break;
                    }
                    case 4: {
                        if (num[1] == '0')
                            finale += lower_Tens[num[0] - '0'];
                        else
                            if (num[0] == 1)
                                switch (num[1]) {
                                case 1:
                                    finale += lower_Tens[11] + " dollars";
                                case 2:
                                    finale += lower_Tens[12] + " dollars";
                                }
                            else
                                finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";
                        break;
                    }
                    case 5: {
                        auto y = lower_Units[std::stoi(num)];
                        finale += y + " dollar";
                        break;
                    }
                    case 6: {
                        finale += lower_Units[0] + " dollars.";
                        break;
                    }
                    }

                    break;
                }
                case 1: {

                    // making millions

                    finale += upper_Units[num[0] - '0'] + " million ";

                    num.erase(0, 1);

                    int count = 0;

                    for (int i = 0; i < num.length(); i++) {

                        if (num[i] == '0') {
                            num.erase(0, 1);
                            count++;
                            continue;
                        }
                    }

                    switch (count) {
                    case 0: {
                        // making thousands

                        // making hundreds
                        finale += lower_Tens[num[0] - '0'] + " hundred ";
                        num.erase(0, 1);

                        // making tens
                        if (num[0] == '0') {
                            if (num[1] != '0')
                                finale += lower_Units[num[1] - '0'] + " thousand ";
                            else
                                finale += " thousand";
                        }
                        else {

                            if (num[0] == 1)
                                switch (num[1]) {
                                case 1:
                                    finale += lower_Tens[11] + " thousand ";
                                case 2:
                                    finale += lower_Tens[12] + " thousand ";
                                }
                            else {

                                if (num[1] == '0')
                                    finale += lower_Tens[num[0] - '0'] + " thousand ";
                                else
                                    finale += lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " thousand ";
                            }
                        }

                        num.erase(0, 2);

                        // making hundreds
                        int count = 0;

                        for (int i = 0; i < num.length(); i++) {

                            if (num[i] == '0') {
                                count++;
                                continue;
                            }
                        }

                        if (count == 1) {

                            if (num == "11")
                                finale += lower_Tens[11];
                            else
                                finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                        }
                        else if (count == 2) {
                            auto y = lower_Units[num[0] - '0'];
                            finale += y + " dollar";
                        }
                        else if (count == 0) {
                            auto y = lower_Units[num[0] - '0'];

                            if (num[1] == 0)
                                finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                            else {

                                if (num[2] == '0')
                                    finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                                else {
                                    num.erase(0, 1);

                                    if (num == "11")
                                        finale += y + " hundred " + lower_Tens[11] + " dollars";
                                    else if (num == "12")
                                        finale += y + " hundred " + lower_Tens[12] + " dollars";
                                    else
                                        finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                                }
                            }
                        }
                        break;
                    }
                    case 1: {
                        // making thousands

                        // making tens

                        if (num[0] == 1)
                            switch (num[1]) {
                            case 1:
                                finale += lower_Tens[11] + " thousand ";
                            case 2:
                                finale += lower_Tens[12] + " thousand ";
                            }
                        else {

                            if (num[1] == '0')
                                finale += lower_Tens[num[0] - '0'] + " thousand ";
                            else
                                finale += lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " thousand ";
                        }


                        num.erase(0, 2);

                        // making hundreds
                        int count = 0;

                        for (int i = 0; i < num.length(); i++) {

                            if (num[i] == '0') {
                                count++;
                                continue;
                            }
                        }

                        if (count == 1) {

                            if (num == "11")
                                finale += lower_Tens[11];
                            else
                                finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                        }
                        else if (count == 2) {
                            auto y = lower_Units[num[0] - '0'];
                            finale += y + " dollar";
                        }
                        else if (count == 0) {
                            auto y = lower_Units[num[0] - '0'];

                            if (num[1] == 0)
                                finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                            else {

                                if (num[2] == '0')
                                    finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                                else {
                                    num.erase(0, 1);

                                    if (num == "11")
                                        finale += y + " hundred " + lower_Tens[11] + " dollars";
                                    else if (num == "12")
                                        finale += y + " hundred " + lower_Tens[12] + " dollars";
                                    else
                                        finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                                }
                            }
                        }
                        break;
                    }
                    case 2: {
                        // making thousands

                        finale += lower_Units[num[0] - '0'] + " thousand ";


                        num.erase(0, 1);

                        // making hundreds
                        int count = 0;

                        for (int i = 0; i < num.length(); i++) {

                            if (num[i] == '0') {
                                count++;
                                continue;
                            }
                        }

                        if (count == 1) {

                            if (num == "11")
                                finale += lower_Tens[11];
                            else
                                finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                        }
                        else if (count == 2) {
                            auto y = lower_Units[num[0] - '0'];
                            finale += y + " dollar";
                        }
                        else if (count == 0) {
                            auto y = lower_Units[num[0] - '0'];

                            if (num[1] == 0)
                                finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                            else {

                                if (num[2] == '0')
                                    finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                                else {
                                    num.erase(0, 1);

                                    if (num == "11")
                                        finale += y + " hundred " + lower_Tens[11] + " dollars";
                                    else if (num == "12")
                                        finale += y + " hundred " + lower_Tens[12] + " dollars";
                                    else
                                        finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                                }
                            }
                        }
                        break;
                    }
                    case 3: {

                        // making hundreds

                        auto y = lower_Units[num[0] - '0'];

                        if (num[1] == 0)
                            finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                        else {

                            if (num[2] == '0')
                                finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                            else {
                                num.erase(0, 1);

                                if (num == "11")
                                    finale += y + " hundred " + lower_Tens[11] + " dollars";
                                else if (num == "12")
                                    finale += y + " hundred " + lower_Tens[12] + " dollars";
                                else
                                    finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                            }
                        }
                        break;
                    }
                    case 4: {
                        if (num[1] == '0')
                            finale += lower_Tens[num[0] - '0'];
                        else
                            if (num[0] == 1)
                                switch (num[1]) {
                                case 1:
                                    finale += lower_Tens[11] + " dollars";
                                case 2:
                                    finale += lower_Tens[12] + " dollars";
                                }
                            else
                                finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";
                        break;
                    }
                    case 5: {
                        auto y = lower_Units[std::stoi(num)];
                        finale += y + " dollar";
                        break;
                    }
                    case 6: {
                        finale += lower_Units[0] + " dollars.";
                        break;
                    }
                    }

                    break;
                }
                case 2: {
                    // making thousands

                    // making hundreds
                    finale += upper_Units[num[0] - '0'] + " hundred ";
                    num.erase(0, 1);

                    // making tens
                    if (num[0] == '0') {
                        if (num[1] != '0')
                            finale += lower_Units[num[1] - '0'] + " thousand ";
                        else
                            finale += " thousand";
                    }
                    else {

                        if (num[0] == 1)
                            switch (num[1]) {
                            case 1:
                                finale += lower_Tens[11] + " thousand ";
                            case 2:
                                finale += lower_Tens[12] + " thousand ";
                            }
                        else {

                            if (num[1] == '0')
                                finale += lower_Tens[num[0] - '0'] + " thousand ";
                            else
                                finale += lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " thousand ";
                        }
                    }

                    num.erase(0, 2);

                    // making hundreds
                    int count = 0;

                    for (int i = 0; i < num.length(); i++) {

                        if (num[i] == '0') {
                            count++;
                            continue;
                        }
                    }

                    if (count == 1) {

                        if (num == "11")
                            finale += lower_Tens[11];
                        else
                            finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                    }
                    else if (count == 2) {
                        auto y = lower_Units[num[0] - '0'];
                        finale += y + " dollar";
                    }
                    else if (count == 0) {
                        auto y = lower_Units[num[0] - '0'];

                        if (num[1] == 0)
                            finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                        else {

                            if (num[2] == '0')
                                finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                            else {
                                num.erase(0, 1);

                                if (num == "11")
                                    finale += y + " hundred " + lower_Tens[11] + " dollars";
                                else if (num == "12")
                                    finale += y + " hundred " + lower_Tens[12] + " dollars";
                                else
                                    finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                            }
                        }
                    }
                    break;
                }
                case 3: {
                    // making thousands

                    // making tens

                    if (num[0] == 1)
                        switch (num[1]) {
                        case 1:
                            finale += upper_Tens[11] + " thousand ";
                        case 2:
                            finale += upper_Tens[12] + " thousand ";
                        }
                    else {

                        if (num[1] == '0')
                            finale += upper_Tens[num[0] - '0'] + " thousand ";
                        else
                            finale += upper_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " thousand ";
                    }


                    num.erase(0, 2);

                    // making hundreds
                    int count = 0;

                    for (int i = 0; i < num.length(); i++) {

                        if (num[i] == '0') {
                            count++;
                            continue;
                        }
                    }

                    if (count == 1) {

                        if (num == "11")
                            finale += lower_Tens[11];
                        else
                            finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                    }
                    else if (count == 2) {
                        auto y = lower_Units[num[0] - '0'];
                        finale += y + " dollar";
                    }
                    else if (count == 0) {
                        auto y = lower_Units[num[0] - '0'];

                        if (num[1] == 0)
                            finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                        else {

                            if (num[2] == '0')
                                finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                            else {
                                num.erase(0, 1);

                                if (num == "11")
                                    finale += y + " hundred " + lower_Tens[11] + " dollars";
                                else if (num == "12")
                                    finale += y + " hundred " + lower_Tens[12] + " dollars";
                                else
                                    finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                            }
                        }
                    }
                    break;
                }
                case 4: {
                    // making thousands

                    finale += upper_Units[num[0] - '0'] + " thousand ";


                    num.erase(0, 1);

                    // making hundreds
                    int count = 0;

                    for (int i = 0; i < num.length(); i++) {

                        if (num[i] == '0') {
                            count++;
                            continue;
                        }
                    }

                    if (count == 1) {

                        if (num == "11")
                            finale += lower_Tens[11];
                        else
                            finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                    }
                    else if (count == 2) {
                        auto y = lower_Units[num[0] - '0'];
                        finale += y + " dollar";
                    }
                    else if (count == 0) {
                        auto y = lower_Units[num[0] - '0'];

                        if (num[1] == 0)
                            finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                        else {

                            if (num[2] == '0')
                                finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                            else {
                                num.erase(0, 1);

                                if (num == "11")
                                    finale += y + " hundred " + lower_Tens[11] + " dollars";
                                else if (num == "12")
                                    finale += y + " hundred " + lower_Tens[12] + " dollars";
                                else
                                    finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                            }
                        }
                    }
                    break;
                }
                case 5: {

                    // making hundreds

                    auto y = upper_Units[num[0] - '0'];

                    if (num[1] == 0)
                        finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                    else {

                        if (num[2] == '0')
                            finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                        else {
                            num.erase(0, 1);

                            if (num == "11")
                                finale += y + " hundred " + lower_Tens[11] + " dollars";
                            else if (num == "12")
                                finale += y + " hundred " + lower_Tens[12] + " dollars";
                            else
                                finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                        }
                    }
                    break;
                }
                case 6: {
                    if (num[1] == '0')
                        finale += upper_Tens[num[0] - '0'];
                    else
                        if (num[0] == 1)
                            switch (num[1]) {
                            case 1:
                                finale += upper_Tens[11] + " dollars";
                            case 2:
                                finale += upper_Tens[12] + " dollars";
                            }
                        else
                            finale += upper_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";
                    break;
                }
                case 7: {
                    auto y = upper_Units[std::stoi(num)];
                    finale += y + " dollar";
                    break;
                }
                case 8: {
                    finale += upper_Units[0] + " dollars.";
                    break;
                }
                }
                break;
            }
            case 7: {
                int count = 0;

                for (int i = 0; i < num.length(); i++) {

                    if (num[0] == '0') {
                        num.erase(0, 1);
                        count++;
                        continue;
                    }
                }

                switch (count) {
                case 0: {

                    // making millions

                    finale += upper_Units[num[0] - '0'] + " million ";

                    num.erase(0, 1);

                    int count = 0;

                    for (int i = 0; i < num.length(); i++) {

                        if (num[i] == '0') {
                            num.erase(0, 1);
                            count++;
                            continue;
                        }
                    }

                    switch (count) {
                    case 0: {
                        // making thousands

                        // making hundreds
                        finale += lower_Units[num[0] - '0'] + " hundred ";
                        num.erase(0, 1);

                        // making tens
                        if (num[0] == '0') {
                            if (num[1] != '0')
                                finale += lower_Units[num[1] - '0'] + " thousand ";
                            else
                                finale += " thousand";
                        }
                        else {

                            if (num[0] == 1)
                                switch (num[1]) {
                                case 1:
                                    finale += lower_Tens[11] + " thousand ";
                                case 2:
                                    finale += lower_Tens[12] + " thousand ";
                                }
                            else {

                                if (num[1] == '0')
                                    finale += lower_Tens[num[0] - '0'] + " thousand ";
                                else
                                    finale += lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " thousand ";
                            }
                        }

                        num.erase(0, 2);

                        // making hundreds
                        int count = 0;

                        for (int i = 0; i < num.length(); i++) {

                            if (num[i] == '0') {
                                count++;
                                continue;
                            }
                        }

                        if (count == 1) {

                            if (num == "11")
                                finale += lower_Tens[11];
                            else
                                finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                        }
                        else if (count == 2) {
                            auto y = lower_Units[num[0] - '0'];
                            finale += y + " dollar";
                        }
                        else if (count == 0) {
                            auto y = lower_Units[num[0] - '0'];

                            if (num[1] == 0)
                                finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                            else {

                                if (num[2] == '0')
                                    finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                                else {
                                    num.erase(0, 1);

                                    if (num == "11")
                                        finale += y + " hundred " + lower_Tens[11] + " dollars";
                                    else if (num == "12")
                                        finale += y + " hundred " + lower_Tens[12] + " dollars";
                                    else
                                        finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                                }
                            }
                        }
                        break;
                    }
                    case 1: {
                        // making thousands

                        // making tens

                        if (num[0] == 1)
                            switch (num[1]) {
                            case 1:
                                finale += lower_Tens[11] + " thousand ";
                            case 2:
                                finale += lower_Tens[12] + " thousand ";
                            }
                        else {

                            if (num[1] == '0')
                                finale += lower_Tens[num[0] - '0'] + " thousand ";
                            else
                                finale += lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " thousand ";
                        }


                        num.erase(0, 2);

                        // making hundreds
                        int count = 0;

                        for (int i = 0; i < num.length(); i++) {

                            if (num[i] == '0') {
                                count++;
                                continue;
                            }
                        }

                        if (count == 1) {

                            if (num == "11")
                                finale += lower_Tens[11];
                            else
                                finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                        }
                        else if (count == 2) {
                            auto y = lower_Units[num[0] - '0'];
                            finale += y + " dollar";
                        }
                        else if (count == 0) {
                            auto y = lower_Units[num[0] - '0'];

                            if (num[1] == 0)
                                finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                            else {

                                if (num[2] == '0')
                                    finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                                else {
                                    num.erase(0, 1);

                                    if (num == "11")
                                        finale += y + " hundred " + lower_Tens[11] + " dollars";
                                    else if (num == "12")
                                        finale += y + " hundred " + lower_Tens[12] + " dollars";
                                    else
                                        finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                                }
                            }
                        }
                        break;
                    }
                    case 2: {
                        // making thousands

                        finale += lower_Units[num[0] - '0'] + " thousand ";


                        num.erase(0, 1);

                        // making hundreds
                        int count = 0;

                        for (int i = 0; i < num.length(); i++) {

                            if (num[i] == '0') {
                                count++;
                                continue;
                            }
                        }

                        if (count == 1) {

                            if (num == "11")
                                finale += lower_Tens[11];
                            else
                                finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                        }
                        else if (count == 2) {
                            auto y = lower_Units[num[0] - '0'];
                            finale += y + " dollar";
                        }
                        else if (count == 0) {
                            auto y = lower_Units[num[0] - '0'];

                            if (num[1] == 0)
                                finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                            else {

                                if (num[2] == '0')
                                    finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                                else {
                                    num.erase(0, 1);

                                    if (num == "11")
                                        finale += y + " hundred " + lower_Tens[11] + " dollars";
                                    else if (num == "12")
                                        finale += y + " hundred " + lower_Tens[12] + " dollars";
                                    else
                                        finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                                }
                            }
                        }
                        break;
                    }
                    case 3: {

                        // making hundreds

                        auto y = lower_Units[num[0] - '0'];

                        if (num[1] == 0)
                            finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                        else {

                            if (num[2] == '0')
                                finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                            else {
                                num.erase(0, 1);

                                if (num == "11")
                                    finale += y + " hundred " + lower_Tens[11] + " dollars";
                                else if (num == "12")
                                    finale += y + " hundred " + lower_Tens[12] + " dollars";
                                else
                                    finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                            }
                        }
                        break;
                    }
                    case 4: {
                        if (num[1] == '0')
                            finale += lower_Tens[num[0] - '0'];
                        else
                            if (num[0] == 1)
                                switch (num[1]) {
                                case 1:
                                    finale += lower_Tens[11] + " dollars";
                                case 2:
                                    finale += lower_Tens[12] + " dollars";
                                }
                            else
                                finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";
                        break;
                    }
                    case 5: {
                        auto y = lower_Units[std::stoi(num)];
                        finale += y + " dollar";
                        break;
                    }
                    case 6: {
                        finale += lower_Units[0] + " dollars.";
                        break;
                    }
                    }

                    break;
                }
                case 1: {
                    // making thousands

                    // making hundreds
                    finale += upper_Tens[num[0] - '0'] + " hundred ";
                    num.erase(0, 1);

                    // making tens
                    if (num[0] == '0') {
                        if (num[1] != '0')
                            finale += lower_Units[num[1] - '0'] + " thousand ";
                        else
                            finale += " thousand";
                    }
                    else {

                        if (num[0] == 1)
                            switch (num[1]) {
                            case 1:
                                finale += lower_Tens[11] + " thousand ";
                            case 2:
                                finale += lower_Tens[12] + " thousand ";
                            }
                        else {

                            if (num[1] == '0')
                                finale += lower_Tens[num[0] - '0'] + " thousand ";
                            else
                                finale += lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " thousand ";
                        }
                    }

                    num.erase(0, 2);

                    // making hundreds
                    int count = 0;

                    for (int i = 0; i < num.length(); i++) {

                        if (num[i] == '0') {
                            count++;
                            continue;
                        }
                    }

                    if (count == 1) {

                        if (num == "11")
                            finale += lower_Tens[11];
                        else
                            finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                    }
                    else if (count == 2) {
                        auto y = lower_Units[num[0] - '0'];
                        finale += y + " dollar";
                    }
                    else if (count == 0) {
                        auto y = lower_Units[num[0] - '0'];

                        if (num[1] == 0)
                            finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                        else {

                            if (num[2] == '0')
                                finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                            else {
                                num.erase(0, 1);

                                if (num == "11")
                                    finale += y + " hundred " + lower_Tens[11] + " dollars";
                                else if (num == "12")
                                    finale += y + " hundred " + lower_Tens[12] + " dollars";
                                else
                                    finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                            }
                        }
                    }
                    break;
                }
                case 2: {
                    // making thousands

                    // making tens

                    if (num[0] == 1)
                        switch (num[1]) {
                        case 1:
                            finale += upper_Tens[11] + " thousand ";
                        case 2:
                            finale += upper_Tens[12] + " thousand ";
                        }
                    else {

                        if (num[1] == '0')
                            finale += upper_Tens[num[0] - '0'] + " thousand ";
                        else
                            finale += upper_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " thousand ";
                    }


                    num.erase(0, 2);

                    // making hundreds
                    int count = 0;

                    for (int i = 0; i < num.length(); i++) {

                        if (num[i] == '0') {
                            count++;
                            continue;
                        }
                    }

                    if (count == 1) {

                        if (num == "11")
                            finale += lower_Tens[11];
                        else
                            finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                    }
                    else if (count == 2) {
                        auto y = lower_Units[num[0] - '0'];
                        finale += y + " dollar";
                    }
                    else if (count == 0) {
                        auto y = lower_Units[num[0] - '0'];

                        if (num[1] == 0)
                            finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                        else {

                            if (num[2] == '0')
                                finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                            else {
                                num.erase(0, 1);

                                if (num == "11")
                                    finale += y + " hundred " + lower_Tens[11] + " dollars";
                                else if (num == "12")
                                    finale += y + " hundred " + lower_Tens[12] + " dollars";
                                else
                                    finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                            }
                        }
                    }
                    break;
                }
                case 3: {
                    // making thousands

                    finale += upper_Units[num[0] - '0'] + " thousand ";


                    num.erase(0, 1);

                    // making hundreds
                    int count = 0;

                    for (int i = 0; i < num.length(); i++) {

                        if (num[i] == '0') {
                            count++;
                            continue;
                        }
                    }

                    if (count == 1) {

                        if (num == "11")
                            finale += lower_Tens[11];
                        else
                            finale += lower_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";

                    }
                    else if (count == 2) {
                        auto y = lower_Units[num[0] - '0'];
                        finale += y + " dollar";
                    }
                    else if (count == 0) {
                        auto y = lower_Units[num[0] - '0'];

                        if (num[1] == 0)
                            finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                        else {

                            if (num[2] == '0')
                                finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                            else {
                                num.erase(0, 1);

                                if (num == "11")
                                    finale += y + " hundred " + lower_Tens[11] + " dollars";
                                else if (num == "12")
                                    finale += y + " hundred " + lower_Tens[12] + " dollars";
                                else
                                    finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                            }
                        }
                    }
                    break;
                }
                case 4: {

                    // making hundreds

                    auto y = upper_Units[num[0] - '0'];

                    if (num[1] == 0)
                        finale += y + " hundred " + lower_Units[num[2] - '0'] + " dollars";
                    else {

                        if (num[2] == '0')
                            finale += y + " hundred " + lower_Tens[num[2] - '0'] + " dollars";
                        else {
                            num.erase(0, 1);

                            if (num == "11")
                                finale += y + " hundred " + lower_Tens[11] + " dollars";
                            else if (num == "12")
                                finale += y + " hundred " + lower_Tens[12] + " dollars";
                            else
                                finale += y + " hundred " + lower_Tens[num[0] - '0'] + "-" + lower_Units[num[1] - '0'] + " dollars";
                        }
                    }
                    break;
                }
                case 5: {
                    if (num[1] == '0')
                        finale += upper_Tens[num[0] - '0'];
                    else
                        if (num[0] == 1)
                            switch (num[1]) {
                            case 1:
                                finale += upper_Tens[11] + " dollars";
                            case 2:
                                finale += upper_Tens[12] + " dollars";
                            }
                        else
                            finale += upper_Tens[num[0] - '0'] + '-' + lower_Units[num[1] - '0'] + " dollars";
                    break;
                }
                case 6: {
                    auto y = upper_Units[std::stoi(num)];
                    finale += y + " dollar";
                    break;
                }
                case 7: {
                    finale += upper_Units[0] + " dollars.";
                    break;
                }
                }
                break;
            }
            }
        }
        else if (x == 1000000000)
            finale += "One billion dollars.";
    }
    else
        std::cout << "Over the limit!";

        std::cout << finale;

        std::cin.get();
        std::cin.get();

        return 0;
}