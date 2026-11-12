// Vjezba 6, zadatak 4: napisite klasu Board iznad main.
#include <iostream>

class Board {
private:
    int m_rows;
    int m_cols;
    char* data;

public:
    Board(int ro, int co, char da)
        : m_rows(ro), m_cols(co) {

        data = new char[m_rows * m_cols];

        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < m_cols; j++) {
                if (i == 0 || i == m_rows - 1 ||
                    j == 0 || j == m_cols - 1) {
                    data[i * m_cols + j] = da;
                }
                else {
                    data[i * m_cols + j] = ' ';
                }
            }
        }
    }

    ~Board() {
        delete[] data;
    }

    // Copy konstruktor - deep copy
    Board(const Board& cp)
        : m_rows(cp.m_rows), m_cols(cp.m_cols) {

        data = new char[m_rows * m_cols];

        for (int i = 0; i < m_rows * m_cols; i++) {
            data[i] = cp.data[i];
        }
    }

    // Postavljanje znaka unutar ruba
    void set(int i, int j, char ch) {
        if (i > 0 && i < m_rows - 1 &&
            j > 0 && j < m_cols - 1) {

            int indeks = i * m_cols + j;
            data[indeks] = ch;
        }
    }

    // Dohvaćanje znaka
    char get(int i, int j) const {
        int indeks = i * m_cols + j;
        return data[indeks];
    }

    int rows() const {
        return m_rows;
    }

    int cols() const {
        return m_cols;
    }

    // Ispis ploče
    void print() const {
        for (int i = 0; i < m_rows * m_cols; i++) {
            std::cout << data[i];

            if (i % m_cols == m_cols - 1) {
                std::cout << '\n';
            }
        }
    }
};

/*
Ocekivani ispis:

    ########
    # @    #
    #      #
    ########
    ########
    # @    #
    #    * #
    ########
    4 8 *


*/
