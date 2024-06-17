#include "List.h"
#include<fstream>
#include<string>
using namespace std;

//это здесь по приколу, не трогай лучше
void generateFile(int n, string path)
{
    ofstream outFile;
    try {
        outFile.open(path);
        for (int i = 0; i < n; i++) {

            string first_names[] = { "Alexander", "Dmitry", "Maxim", "Ivan", "Anatoly", "Vadim", "Gennady", "Sergey", "Andrey", "Nikolai", "Pavel", "Oleg", "Vladimir", "Artem", "Konstantin", "Gregory", "Yuri",
                            "Victor", "Eugene", "Igor", "Roman", "Mikhail", "Vitaly", "Stanislav", "Denis", "Alexey", "Peter", "Fedor", "Timur", "Svyatoslav", "Valery", "Alexander", "Marat", "Anton", "Arthur", "Daniel", "Eduard", "Arseny",
                            "Gleb", "Egor", "Leonid", "Ilya", "Vyacheslav", "David", "Semyon", "Ivan", "Boris", "Maxim", "Matthew", "Kirill", "Philip", "Dmitry", "Vasily", "Andrey", "Antonio", "Donato", "Ignatius", "Leon", "Luke",
                            "Mark", "Miron", "Nikita", "Oscar", "Rodion", "Rostislav", "Ruslan", "Svyatopolk", "Sergey", "Spartak", "Timofey", "Fedor", "Felix", "Khariton", "Emil", "Eric", "Yuri", "Yaroslav", "Alexey", "Andrey", "Anton",
                            "Artem", "Valery", "Vasily", "Victor", "Vitaly", "Gennady", "Gregory", "David", "Daniel", "Denis", "Dmitry", "Eugene", "Egor", "Ivan", "Ignatius", "Igor", "Ilya", "Kirill", "Konstantin", "Leonid", "Luka",
                            "Maxim", "Marat", "Mark", "Matthew", "Mikhail", "Nikita", "Nikolay", "Oleg", "Oscar", "Pavel", "Peter", "Rodion", "Roman", "Rostislav", "Ruslan", "Svyatoslav", "Semyon", "Sergey", "Spartak", "Stanislav",
                            "Timofey", "Timur", "Fedor", "Felix", "Philip", "Khariton", "Eduard", "Emil", "Eric", "Yuri" };
            string last_names[] = { "Ivanov", "Smirnov", "Kuznetsov", "Popov", "Sokolov", "Lebedev", "Kozlov", "Novikov", "Morozov", "Petrov", "Volkov", "Solovyov", "Vasiliev", "Zaitsev", "Pavlov", "Semenov", "Golubev",
                            "Vinogradov", "Bogdanov", "Vorobyov", "Fedorov", "Mikhailov", "Belyaev", "Tarasov", "Belov", "Komarov", "Orlov", "Kiselyov", "Makarov", "Andreev", "Kovalev", "Ilyin", "Gusev", "Titov", "Kuzmin", "Kudryavtsev",
                            "Baranov", "Kulikov", "Alekseev", "Stepanov", "Yakovlev", "Sorokin", "Sergeev", "Romanov", "Zakharov", "Borisov", "Korolev", "Gerasimov", "Ponomarev", "Grigoriev", "Lazarev", "Medvedev", "Ershov", "Nikitin",
                            "Sobolev", "Ryabov", "Polyakov", "Tsvetkov", "Danilov", "Zhukov", "Frolov", "Shcherbakov", "Kotov", "Grishin", "Matveev", "Dorofeev", "Zhuravlev", "Ovchinnikov", "Trofimov", "Leonov", "Safonov", "Kondratiev",
                            "Kopylov", "Dyachkov", "Savin", "Timofeev", "Fomin", "Chernov", "Abramov", "Martynov", "Efimov", "Fedotov", "Shchukin", "Bykov", "Alexandrov", "Petukhov", "Polyakov", "Loginov", "Safonov", "Kolesnikov" };
            string middle_names[] = { "Alexandrovich", "Dmitrievich", "Maksimovich", "Ivanovich", "Anatolyevich", "Vadimovich", "Gennadievich", "Sergeevich", "Andreevich", "Nikolaevich", "Pavlovich", "Olegovich", "Vladimirovich",
                            "Artemovich", "Konstantinovich", "Grigorievich", "Yurievich", "Viktorovich", "Evgenievich", "Igorevich", "Romanovich", "Mikhailovich", "Vitalievich", "Stanislavovich", "Denisovich", "Alekseevich", "Petrovich",
                            "Fedorovich", "Timurovich", "Svyatoslavovich", "Valerievich", "Alexandrovich", "Maratovich", "Antonovich", "Arturovich", "Daniilovich", "Eduardovich", "Arsenievich", "Glebovich", "Egorovich", "Leonidovich",
                            "Ilyich", "Vyacheslavovich", "Davidovich", "Semenovich", "Ivanovich", "Borisovich", "Maksimovich", "Matveevich", "Kirillovich", "Filippovich", "Dmitrievich", "Vasilyevich", "Andreevich", "Antonievich",
                            "Donatovich", "Ignatievich", "Leonovich", "Lukyanovich", "Markovich", "Mironovich", "Nikitich", "Oskarovich", "Rodionovich", "Rostislavovich", "Ruslavovich", "Svyatopolkovich", "Sergeevich", "Spartakovich",
                            "Timofeevich", "Fedorovich", "Feliksovich", "Kharitonovich", "Emilevich", "Erikovich", "Yurievich", "Yaroslavovich", "Alekseevich", "Andreevich", "Antonovich", "Artemovich", "Valerievich", "Vasilyevich",
                            "Viktorovich", "Vitalievich", "Gennadievich", "Grigorievich", "Davidovich", "Daniilovich", "Denisovich", "Dmitrievich", "Evgenievich", "Egorovich", "Ivanovich", "Ignatievich", "Igorevich", "Ilyich", "Kirillovich",
                            "Konstantinovich", "Leonidovich", "Lukyanovich" };

            char groupChar[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

            string studentData = last_names[rand() % 90] + " " + first_names[rand() % 100] + " " + middle_names[rand() % 100] + ' ' + groupChar[rand() % 25];
            outFile << studentData << rand() % 899 + 100  << '\n';
        }
        outFile.close();
    }
    catch (exception e) {
        cout << e.what() << '\n';
    }
}




int main()
{


    /*List list;
    

    list.add(3);
    list.add(27);
    list.add(9);

    for (auto it = list.begin(); it != list.end(); it++) {
        std::cout << *it << ' ';
    }

    std::cout << '\n';

    list.swap(0, 2);


    for (auto it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << ' ';
    }

    std::cout << '\n';

    for (auto&& it : list) {
        std::cout << it << ' ';
    }*/

    ListT<char> str;

    str.add('a');
    str.add('b');
    str.add('3');
    str.add('c');
    str.add('5');

    str.printList();

    auto it = str.begin();

    for (; it != str.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}
