#include <iostream>
#include <stdexcept>

class Drob
{
private:
    int ch; //проверка 
    int zn; 

public:
    Drob(int chVal = 0, int znVal = 1) : ch(chVal), zn(znVal)
    {
        if (zn == 0)
        {
            throw std::invalid_argument("Знаменатель не может быть равен 0");
        }
    }

    Drob add(const Drob &dr) const
    {
        int newCh = ch * dr.zn + dr.ch * zn;
        int newZn = zn * dr.zn;
        return Drob(newCh, newZn);
    }

    Drob sub(const Drob &dr) const
    {
        int newCh = ch * dr.zn - dr.ch * zn;
        int newZn = zn * dr.zn;
        return Drob(newCh, newZn);
    }

    Drob mul(const Drob &dr) const
    {
        int newCh = ch * dr.ch;
        int newZn = zn * dr.zn;
        return Drob(newCh, newZn);
    }

    Drob del(const Drob &dr) const
    {
        if (dr.ch == 0)
        {
            throw std::invalid_argument("Деление на ноль недопустимо");
        }

        int newCh = ch * dr.zn;
        int newZn = zn * dr.ch;
        return Drob(newCh, newZn);
    }

    friend std::ostream &operator<<(std::ostream &out, const Drob &dr)
    {
        out << dr.ch << '/' << dr.zn;
        return out;
    }

    friend std::istream &operator>>(std::istream &in, Drob &dr)
    {
        std::cout << "Введите числитель: ";
        in >> dr.ch;
        std::cout << "Введите знаменатель: ";
        in >> dr.zn;

        if (dr.zn == 0)
        {
            throw std::invalid_argument("Знаменатель не может быть равен нулю");
        }

        return in;
    }
};

int main()
{
    try
    {
        Drob d1, d2;
        std::cin >> d1 >> d2;

        Drob sum = d1.add(d2);
        Drob razn = d1.sub(d2);
        Drob proizvedeniye = d1.mul(d2);
        Drob chastnoe = d1.del(d2);

        std::cout << "Сумма: " << sum << std::endl;
        std::cout << "Разность: " << razn << std::endl;
        std::cout << "Произведение: " << proizvedeniye << std::endl;
        std::cout << "Частное: " << chastnoe << std::endl;
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Ошибка: " << ex.what() << "!!!!" <<std::endl;
    }

    return 0;
}
