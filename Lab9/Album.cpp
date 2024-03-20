#include "Album.h"
#include <iostream>
#include <vector>
int Album::totalAlbums = 0;
double Album::totalSales = 0;

void Album::purchaseAlbum() {
    if (copiesAvailable > 0) {
    copiesAvailable -= 1;
    totalAlbums -= 1;
    totalSales += price;
    std::cout << "Album purchased" << "\n";
    }
    else {
        std::cout << "No avaliable copies" << "\n";
    }

}
int Album::getTotalAlbums() {
    return totalAlbums;
}
double Album::getTotalSales() {
    return totalSales;
}
