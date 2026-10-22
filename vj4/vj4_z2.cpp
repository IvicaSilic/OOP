#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

struct Song {
    std::string title;
    std::string artist;
    int year;
    int plays;
};

void print_song(const Song& s) {
    std::cout << s.title << " - " << s.artist << " (" << s.year << "), slusanja: " << s.plays << '\n';
}

int main() {
    std::vector<Song> songs{
        {"Bohemian Rhapsody", "Queen", 1975, 950},
        {"Imagine", "John Lennon", 1971, 800},
        {"Hey Jude", "The Beatles", 1968, 700},
        {"Yesterday", "The Beatles", 1965, 650},
        {"Under Pressure", "Queen", 1981, 500},
        {"Let It Be", "The Beatles", 1970, 720},
    };

    std::sort(songs.begin(), songs.end(), [](const Song& a, const Song& b) {
        return a.year != b.year ? a.year < b.year : a.title < b.title;
    });
    std::cout << "Popis po godini:\n";
    for (const auto& s : songs)
        print_song(s);

    std::string artist;
    std::cout << "\nIme izvodaca: ";
    std::cin >> std::ws;
    std::getline(std::cin, artist);

    std::vector<Song> od_izvodaca;
    std::copy_if(songs.begin(), songs.end(), std::back_inserter(od_izvodaca),
                 [&artist](const Song& s) { return s.artist == artist; });

    if (od_izvodaca.empty()) {
        std::cout << "Nema pjesama izvodaca " << artist << '\n';
    } else {
        std::cout << "Broj pjesama: " << od_izvodaca.size() << '\n';
        std::cout << "Najstarija: ";
        print_song(*std::min_element(od_izvodaca.begin(), od_izvodaca.end(),
                                     [](const Song& a, const Song& b) { return a.year < b.year; }));
    }

    auto najslusanija = std::max_element(songs.begin(), songs.end(),
                                         [](const Song& a, const Song& b) { return a.plays < b.plays; });
    std::cout << "Najslusanija: ";
    print_song(*najslusanija);
}
