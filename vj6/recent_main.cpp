// Vjezba 6, zadatak 6: napisite klasu RecentlyPlayed iznad main.
#include <cassert>
#include <iostream>
#include <string>

class RecentlyPlayed {
private:
    std::string* buf;
    int cap;
    int head;
    int count;
public:
    RecentlyPlayed(int n) : buf(new std::string[n]), cap(n), head(0), count(0) {}

    RecentlyPlayed(const RecentlyPlayed& other)
        : buf(new std::string[other.cap]), cap(other.cap), head(other.head), count(other.count) {
        for (int i = 0; i < cap; i++) {
            buf[i] = other.buf[i];
        }
    }

    RecentlyPlayed& operator=(const RecentlyPlayed& other) {
        if (this != &other) {
            std::string* novi = new std::string[other.cap];
            for (int i = 0; i < other.cap; i++) {
                novi[i] = other.buf[i];
            }
            delete[] buf;
            buf = novi;
            cap = other.cap;
            head = other.head;
            count = other.count;
        }
        return *this;
    }

    ~RecentlyPlayed() {
        delete[] buf;
    }

    void play(const std::string& title) {
        buf[head] = title;
        head = (head + 1) % cap;
        if (count < cap) {
            count++;
        }
    }

    int size() const { return count; }
    int capacity() const { return cap; }

    std::string get(int i) const {
        if (i < 0 || i >= count) {
            return "";
        }
        return buf[(head - 1 - i + cap) % cap];
    }

    void print() const {
        for (int i = 0; i < count; i++) {
            std::cout << get(i) << " ";
        }
        std::cout << std::endl;
    }
};


int main()
{
    RecentlyPlayed recent(3);
    recent.play("Heroes");
    recent.play("Literary Mind");
    std::cout << recent.size() << ' ' << recent.capacity() << '\n';
    recent.play("Sports");
    recent.print();
    recent.play("Henry Don't Got Love");     // buffer je pun: prepisuje se najstarija
    recent.print();

    RecentlyPlayed copy = recent;             // copy konstruktor
    recent.play("Guided by Angels");
    recent.print();
    copy.print();
    std::cout << copy.get(0) << '\n';
    return 0;
}

/*
Ocekivani ispis:

    2 3
    Sports, Literary Mind, Heroes
    Henry Don't Got Love, Sports, Literary Mind
    Guided by Angels, Henry Don't Got Love, Sports
    Henry Don't Got Love, Sports, Literary Mind
    Henry Don't Got Love
*/
