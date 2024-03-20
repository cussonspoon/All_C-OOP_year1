#include <iostream>
#include <list>

class QuizQuestion
{
public:
    std::string question;
    char answer;

    QuizQuestion(std::string question, char answer) : question(question), answer(answer) {}

    void displayQuestion() const
    {
        std::cout << question;
    }

    int checkAnswer(char ans) const
    {
        switch (ans)
        {
        while(true){
        case 'a':
        case 'A':
        case 'b':
        case 'B':
        case 'c':
        case 'C':
            if (answer == ans)
            {
                std::cout << "Correct!" << "\n";
                return 1;
            }
            else
            {
                std::cout << "Wrong answer." << "\n";
                return 0;
            }
        default:
            std::cout << "Invalid choice!" << "\n";
            continue;
        }
        }
    }
};

int main()
{
    std::list<QuizQuestion> quizList = {
        {"What is the capital of France?\na) Berlin\nb) Paris\nc) London", 'b'},
        {"Which planet is known as the Red Planet?\na) Mars\nb) Jupiter\nc) Saturn", 'a'},
        {"What is the largest mammal?\na) Elephant\nb) Blue Whale\nc) Giraffe", 'b'},
        {"Who wrote 'Hamlet'?\na) Mark Twain\nb) Charles Dickens\nc) William Shakespeare", 'c'},
        {"What is the chemical symbol for water?\na) H2O\nb) CO2\nc) O2", 'a'},
    };

    int count = 1;
    int score = 0;
    char userinput;

    for (const auto &element : quizList)
    {
        std::cout << "Question " << count << ": ";
        element.displayQuestion();
        std::cout << "\n"
                  << "Your answer: ";
        std::cin >> userinput;
        score += element.checkAnswer(userinput);
        count++;
    }

    std::cout << "Your total score: " << score << "/" << quizList.size() << std::endl;

    return 0;
}
