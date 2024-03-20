#include <iostream>
#include <vector>
#include "Album.h"

void Album::listallAlbums(){
    std::cout << title << " by " << artist << " - $" << price << " (" << copiesAvailable << " copies available)" << "\n";
}
void Album::DisplaySaleStatistics(){
    std::cout << "Total Albums in inventory : " << totalAlbums << "\n";
    std::cout << "Total sale made: $" << totalSales << "\n"; 
}
int main() {
std::vector<Album> albums;
albums.emplace_back("Abbey Road", "The Beatles", 19.99, 5);
albums.emplace_back("The Dark Side of the Moon", "Pink Floyd", 21.99, 3);
albums.emplace_back("Hotel California", "Eagles", 15.99, 4);
albums.emplace_back("Back in Black", "AC/DC", 20.99, 2);
albums.emplace_back("Rumours", "Fleetwood Mac", 16.99, 3);
albums.emplace_back("Thriller", "Michael Jackson", 18.99, 5);
albums.emplace_back("The Wall", "Pink Floyd", 22.99, 2);
albums.emplace_back("Led Zeppelin IV", "Led Zeppelin", 17.99, 3);
while (true){
    int choice;
    std::cout << "Online Music Store Menu:\n1. List all albums\n2. Purchase an album\n3. Display sales statistics\n4. Exit\nEnter your choice: ";
    std::cin >> choice;
    if (choice == 1){
        std::cout << "Avaliable Albums: " << "\n";
        int count = 1;
        for (Album al : albums){
            std::cout << count << ". ";
            al.listallAlbums();
            count++;
        }
    }
    else if (choice == 2){
        int choice2;
        std::cout << "Which do you want to purchase: ";
        std::cin >> choice2;
        try
        {
            albums[choice2 - 1].purchaseAlbum();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            std::cout << "The selected one does not exists" << "\n";
        }
    }
    else if (choice == 3){
        albums[0].DisplaySaleStatistics();
    }
    else if (choice == 4){
        std::cout << "Thank you for using the online music store.";
        break;
    }
    else{
        std::cout << "Invalid choice, please try again.";
        continue;
    }
}
return 0;
}