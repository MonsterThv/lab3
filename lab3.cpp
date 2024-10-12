#include <iostream>
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include <map>

using namespace std;

template<class T>
std::vector<T> generate_random_vector(std::size_t num, T min = -10, T max = 10)
{
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_real_distribution<> dist(min, max);

    auto lambda = [&e2, &dist]() -> T { return dist(e2); };

    std::vector<T> result(num);
    std::generate_n(result.begin(), num, lambda);
    return result;
}


void task1() {
    int n;
    int a;
    cout << "input lenght - ";
    cin >> n;
    cout << "input a - ";
    cin >> a;
    vector<int> v = generate_random_vector<int>(n, 1, 100);
    cout << "initial array" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
        v[i] = v[i] * 2;
        v[i] = v[i] - a;
        v[i] = v[i] / v[0];
    }
    cout << "array after transformations" << endl;
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

void task2() {
    int n;
    int k1;
    int k2;
    int s1;
    int s2;

    cout << "input lenght - ";
    cin >> n;

    do {
    cout << "input k1 - ";
    cin >> k1;
    } while (k1 > n);

    do {
        cout << "input k2 - ";
        cin >> k2;
    } while (k2 <= k1 || k2 > n);

    do {
        cout << "input s1 - ";
        cin >> s1;
    } while (s1 > n);

    do {
        cout << "input s2 - ";
        cin >> s2;
    } while (s2 <= s1 || s2 > n);

    vector<int> v = generate_random_vector<int>(n, 1, 100);
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    int sum4 = 0;
    int sum5 = 0;
    for (int i = 0; i < v.size(); i++) {
        sum1 = sum1 + v[i];
        sum2 = sum2 + (v[i] * v[i]);
    }
    for (int i = 0; i < 6; i++) {
        sum3 = sum3 + v[i];
    }
    for (int i = k1; i < k2; i++) {
        sum4 = sum4 + v[i];
    }
    for (int i = s1; i < s2; i++) {
        sum5 = sum5 + v[i];
    }
    cout << "sum of all the elements - " << sum1 << endl;
    cout << "sum of the squares of all the elements - " << sum2 << endl;
    cout << "sum of the first six elements - " << sum3 << endl;
    cout << "sum of the array elements from k1 to k2 - " << sum4 << endl;
    cout << "arithmetic mean - " << sum1 / v.size() << endl;
    cout << "arithmetic mean of the array elements from s1 to s2 - " << sum5 / (s2 - s1 + 1) << endl;
}

void task3() {
    vector<int> v = generate_random_vector<int>(20, 1, 100);
    cout << "initial array" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    int a = v.size();
    for (int i = 0; i < 3; i++) {
        int temp = v[a + i - 3];
        v[a + i - 3] = v[i];
        v[i] = temp;
    }
    cout << "array after transformations" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}

void task4() {
    int n;
    cout << "input lenght - ";
    cin >> n;
    vector<int> v = generate_random_vector<int>(n, -100, 100);

    cout << "initial array" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] < 0) {
            v.erase(v.begin() + i);
            break;
        }
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] % 2 == 0) {
            v.erase(v.begin() + i);
            break;
        }
    }

    cout << "array after transformations" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}

void task5() {
    string city;
    cout << "input city - ";
    cin >> city;
    if (city.size() % 2 == 0) {
        cout << " % 2 = 0";
    }
    else {
        cout << " % 2 != 0";
    }
}

void task6() {
    string sn1;
    string sn2;
    cout << "input second name 1 - ";
    cin >> sn1;
    cout << "input second name 2 - ";
    cin >> sn2;
    if (sn1.size() > sn2.size()) {
        cout << "sn1 > sn2";
    }
    if (sn1.size() == sn2.size()) {
        cout << "sn1 = sn2";
    } 
    if (sn1.size() < sn2.size()) {
        cout << "sn1 < sn2";
    }
}

void task7() {
    string city1;
    string city2;
    string city3;
    cout << "input city1 - ";
    cin >> city1;
    cout << "input city2 - ";
    cin >> city2;
    cout << "input city3 - ";
    cin >> city3;

    vector<string> v = { city1 , city2 , city3 };
    
    int max_size = 0;
    for (int i = 0; i < v.size(); i++) {
        if (max_size < v[i].size()) {
            max_size = v[i].size();
        }
    }
    for (int i = 0; i < v.size(); i++) {
        if (max_size == v[i].size()) {
            cout << v[i];
        }
    }
}

void task8() {
    string word;
    int m;
    int n;
    cout << "input word - ";
    cin >> word;
    do {
        cout << "input m - ";
        cin >> m;
    } while (m <= 0 || m > word.size());
    do {
        cout << "input n - ";
        cin >> n;
    } while (n < 0 || n > word.size() || n < m);

    for (int i = m - 1; i < n; i++) {
        cout << word[i];
    }
}

void task9() {
    string word;
    cout << "input word - ";
    cin >> word;
    int n = word.size();
    for (int i = 0; i < n; i++) {
        word.push_back('*');
    }
    for (int i = 0; i < n; i++) {
        word.insert(word.begin(), '*');
    }
    cout << word;
}

void task10() {
    string st;
    float res;
    cout << "input string - ";
    cin >> st;
    int count_a = 0;
    for (int i = 0; i < st.size(); i++) {
        if (st[i] == 'a') {
            count_a++;
        }
    }
    res = (float(count_a) / float(st.size())) * 100;
    cout << res << '%';
}
void task11() {
    string st = "              Can you can, a. can as a canner can can a can?        ";
    string word;
    string answer;
    cout << "input word - ";
    cin >> word;
    // убираем лишние пробелы
    while (st[0] == ' ') {
        st.erase(st.begin());
    }
    while (st[st.size() - 1] == ' ') {
        st.erase(st.begin() + st.size() - 1);
    }

    int count_space = 0;
    for (int i = 0; i < st.size(); i++) {
        if (st[i] == ' ') {
            count_space++;
        }
    }
    // разбиваем предложение на слова
    vector<string> v(count_space + 1);
    vector<char> ch(0);
    vector<int> place(0);
    int word_number = 0;
    for (int i = 0; i < st.size(); i++) {
        if (st[i] != ' ') {
            v[word_number].push_back(st[i]);
        }
        else
        {
            word_number++;
        }
    }
    // удаляем не буквенные элементы в отдельных словах, сохраняя их положение и значение
    for (int i = 0; i < v.size(); i++) {
        if (int(v[i][v[i].size() - 1]) < 65) {
            ch.push_back(v[i][v[i].size() - 1]);
            place.push_back(i);
            v[i].erase(v[i].begin() + v[i].size() - 1);
        }
    }
    // заменяем can на введённое слово
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == "can" || v[i] == "Can") {
            v[i] = word;
        }
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            answer.push_back(v[i][j]);
        }
        if (i == place[0]) {
            answer.push_back(ch[0]);
            place.erase(place.begin());
            ch.erase(ch.begin());
        }
        answer.push_back(' ');
    }
    answer.erase(answer.begin() + answer.size() - 1);
    cout << answer;

}


int main()
{
    int number;
    cout << "input task number - ";
    cin >> number;
    switch (number)
    {
    case 1 :
        task1();
        break;
    case 2:
        task2();
        break;
    case 3:
        task3();
        break;
    case 4:
        task4();
        break;
    case 5:
        task5();
        break;
    case 6:
        task6();
        break;
    case 7:
        task7();
        break;
    case 8:
        task8();
        break;
    case 9:
        task9();
        break;
    case 10:
        task10();
        break;
    case 11:
        task11();
        break;

    }
}
