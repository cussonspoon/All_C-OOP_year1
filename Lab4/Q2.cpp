#include <iostream>
#include <vector>
#include <string>


class Book {
public:
    std::string title;
    std::string author;
    int quantity;

public:
    Book(std::string title, std::string author, int quantity) : title(title), author(author), quantity(quantity) {}

    void set_book(std::string new_title, std::string new_author, int new_quantity) {
        title = new_title;
        author = new_author;
        quantity = new_quantity;
    }
};

class Inventory {
    private:
        std::vector<Book> bag;
    public:
        void add_book(std::string title, std::string author, int quantity){
            Book book_temp(title, author, quantity);
            bag.push_back(book_temp);
        }
        void find_book(std::string find_title) {
            for (const Book& element : bag) {
                if (element.title == find_title) {
                    std::cout << "Book found: " << element.title << "," << element.author << "," << element.quantity << "\n";
                    return;
                }
            }
            std::cout << "Book not found.\n";
        };
        void print_all_book(){
            for (const Book& element : bag){
                std::cout << "Title : " << element.title << " , Author : " << element.author << " , Quantity : " << element.quantity << "\n";
            }
        }
        void remove_book(std::string remove_title) {
            for (auto it = bag.begin(); it != bag.end(); ++it) {
                if (it->title == remove_title) {
                    bag.erase(it);
                    std::cout << "Book removed.\n";
                    return;
                }
            }
            std::cout << "Book not found.\n";
        }
        };

int main(){
    Inventory bag;
    while (true){
        char input;
        std::cout << "Enter a command (a : add, r : remove, s : search, l : list, q : quit): ";
        std::cin >> input;
        if (input == 'a'){
            std::string new_title;
            std::string new_author;
            double quantity_check;
            std::cout << "Enter title: ";
            std::cin >> new_title;
            std::cout << "Enter author: ";
            std::cin >> new_author;
            std::cout << "Enter quantity: ";
            if (!(std::cin >> quantity_check)) {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "Invalid input, quantity must be a whole number.\n";
                    continue;
            }
            if (quantity_check != static_cast<int>(quantity_check)) {
                std::cout << "Invalid input, quantity must be a whole number.\n";
                continue;
            }

            int quantity = static_cast<int>(quantity_check);
            bag.add_book(new_title, new_author, quantity);
            std::cout << "Book added." << "\n";
            
        }
        else if (input == 'r'){
            std::string remove_title;
            std::cout << "Enter a title to remove: ";
            std::cin >> remove_title;
            bag.remove_book(remove_title);
        }
        else if (input == 's'){
            std::string search_title;
            std::cout << "Enter a title to search: ";
            std::cin >> search_title;
            bag.find_book(search_title);
        }
        else if (input == 'l'){
            bag.print_all_book();
        }
        else if (input == 'q'){
            break;
        }
        else{
            std::cout << "Invalid command" << "\n";
            continue;
        }
    }
}
