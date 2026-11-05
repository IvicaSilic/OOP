// Vježba 5, zadatak 3
// Prema dijagramu klasa napišite klase Song i Album.
//   Album: - title: string, - year: int, - songs: vector<Song>
//          + Album(t: string, y: int, first: Song), + add(s: Song): bool,
//          + duration(): int const, + print() const
//   Song:  + title: string, + artist: string, + seconds: int
//   Veza: Album 1 — 1..* Song (kompozicija)
// - Multiplicitet 1..* je invarijanta: album nikad nije prazan. Zato konstruktor prima
//   prvu pjesmu.
// - add ne dodaje pjesmu ako album već ima pjesmu istog naslova i tada vraća false.
// - duration() vraća ukupno trajanje u sekundama, a print() ispisuje album u obliku
//   kao ispod.

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

// ovdje napisite Song i Album
struct Song {
    std::string title;
    std::string artist;
    int seconds;
};

class Album {
    std::string title;
    int year;
    std::vector<Song> songs;  

public:
    Album(const std::string& t, int y, const Song& first) : title(t), year(y), songs(1, first) {}

    bool add(const Song& s) {
        for (const Song& existing : songs)
            if (existing.title == s.title) return false;
        songs.push_back(s);
        return true;
    }

    int duration() const {
        int total = 0;
        for (const Song& s : songs) total += s.seconds;
        return total;
    }

    void print() const {
        int total = duration();
        std::cout << title << " (" << year << "), " << songs.size() << " pjesme, "
                  << total / 60 << ':' << std::setw(2) << std::setfill('0') << total % 60 << '\n';
        for (std::size_t i = 0; i < songs.size(); ++i)
            std::cout << "  " << i + 1 << ". " << songs[i].title << '\n';
    }
};

int main()
{
    Album a("Sol Invictus", 2015, {"Sol Invictus", "Faith No More", 156});
    a.add({"Superhero", "Faith No More", 315});
    a.add({"Matador", "Faith No More", 368});
    std::cout << a.add({"Superhero", "Faith No More", 315}) << '\n';   // vec postoji
    a.print();
    return 0;
}

/*
Ocekivani ispis:

    0
    Sol Invictus (2015), 3 pjesme, 13:59
      1. Sol Invictus
      2. Superhero
      3. Matador
*/
