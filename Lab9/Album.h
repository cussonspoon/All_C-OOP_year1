#ifndef ALBUM_H
#define ALBUM_H
#include <string>
#include <vector>
class Album
{
public:
    std::string title;
    std::string artist;
    double price;
    double copiesAvailable;
    static int totalAlbums;
    static double totalSales;
    void purchaseAlbum();
    int getTotalAlbums();
    double getTotalSales();
    void listallAlbums();
    void DisplaySaleStatistics();
    Album(const std::string &title, const std::string &artist, double price, int copies)
        : title(title), artist(artist), price(price), copiesAvailable(copies)
    {
        totalAlbums += copies;
    }
};
#endif
