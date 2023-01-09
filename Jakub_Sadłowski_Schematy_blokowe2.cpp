#include <iostream>;
#include <ctime>;
#include <cstdlib>;
#include <math.h>
#include <cmath>;
#include <regex>
#include <list>
using namespace std;

/*
Dany jest zbiór n pi³ek, z których ka¿da jest pokolorowana na jeden z k kolorów. Narysuj schemat
blokowy algorytmu, który obliczy, jakiego koloru pi³ek jest najwiêcej. Zaimplementuj rozwi¹zanie.
*/
class Exercise002
{
private:

	struct InputParameters
	{
		int noOfColors = 0;
		int noOfBalls = 0;
	};
	
	bool readInputFromTerminal(InputParameters* p)
	{
		cout << "Podaj ilosc pilek: ";
		cin >> p -> noOfBalls;
		if (p -> noOfBalls < 1 || cin.fail())
		{
			cout << "Niepoprawna ilosc pilek, podaj przynajmniej 1";
			return false;
		}
		cout << "Podaj na ile kolorow zabarwic pilki: ";
		cin >> p -> noOfColors;
		if (p -> noOfColors < 1 || cin.fail())
		{
			cout << "Niepoprawna ilosc kolorow, podaj przynajmniej 1";
			return false;
		}
		return true;
	}

	int* randomlyAssignColorsToBalls(InputParameters p)
	{
		int* balls = new int[p.noOfBalls];

		srand(time(0));
		for (int i = 0; i < p.noOfBalls; i++)
		{
			balls[i] = rand() % p.noOfColors;
		}
		return balls;
	}

	void displayArray(int* arr, int noOfElements, string title)
	{
		cout << title;
		for (int i = 0; i < noOfElements; i++)
		{
			cout << arr[i] << " ";
		}
	}

	int* countNoOfBallsPerColor(int* balls, InputParameters p)
	{
		int* colorsCounter = new int[p.noOfColors];
		std::fill_n(colorsCounter, p.noOfColors, 0);

		for (int i = 0; i < p.noOfBalls; i++)
		{
			int color = balls[i];
			colorsCounter[color] += 1;
			
		}
		return colorsCounter;
	}

	int findDominantColor(InputParameters p, int* colorsCounter)
	{
		int dominantColor = 0;
		for (int i = 0, maxCounter = 0; i < p.noOfColors; i++)
		{
			int noOfBallsOfColor = colorsCounter[i];
			if (noOfBallsOfColor > maxCounter)
			{
				maxCounter = colorsCounter[i];
				dominantColor = i;
			}
		}
		return dominantColor;
	}

public:

	void execute()
	{
		InputParameters params;
		if (!readInputFromTerminal(&params)) return;
		int* balls = randomlyAssignColorsToBalls(params);
		displayArray(balls, params.noOfBalls, "Tablica z pokolorowanymi pilkami: ");
		int* colorsCounter = countNoOfBallsPerColor(balls, params);
		int dominantColor = findDominantColor(params, colorsCounter);
		int noOfBallsForDominantColor = colorsCounter[dominantColor];
		cout << "\nDla podanych parametrow, najwiecej jest pilek o kolorze: " << dominantColor
			<< " i jest ich : " << noOfBallsForDominantColor;
	}
};

/*
Dany jest zbiór odcinków o iloœci odcinków równej n. Ka¿dy z odcinków jest reprezentowany przez
wspó³rzêdne jego koñców. Stwórz funkcjê, która znajdzie najkrótszy odcinek z tego zbioru. Narysuj
schemat blokowy funkcji.
*/
class Exercise003
{

    class Point
    {
    public:
        int x, y;
        Point() {}
        Point(int x1, int y1)
        {
            x = x1;
            y = y1;
        }

        string toString()
        {
            return "(" + to_string(x) + "," + to_string(y) + ")";
        }
    };

    class Section
    {
    public:
        Point p1, p2;
        double length;

        Section() {}
        Section(int x1, int y1, int x2, int y2)
        {
            this->p1 = Point(x1, y1);
            this->p2 = Point(x2, y2);
            this->length = calcSegmentLenght();
        }

        double calcSegmentLenght()
        {
            return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
        }

        string toString()
        {
            return "[" + p1.toString() + "," + p2.toString() + "]";
        }
    };

    class ConsoleInputParser
    {
    private:
        string regexSection = "\\[\\((\\d+),(\\d+)\\),\\((\\d+),(\\d+)\\)],?";
        string regexInput = "^(" + regexSection + ")+$";
        list<Section> sectionsList;

    public:
        list<Section> getSectionList()
        {
            return sectionsList;
        }

        bool parseInput(string input)
        {
            if (!validateWholeInput(input))
            {
                return false;
            }

            parseSections(input);

            return true;
        }

    private:
        void parseSections(string input)
        {

            regex regexpSection(regexSection);
            smatch matches;

            string searchString = input;
            while (regex_search(searchString, matches, regexpSection))
            {
                Section s(stoi(matches.str(1)), stoi(matches.str(2)), stoi(matches.str(3)), stoi(matches.str(4)));
                // cout << "\nSection[(" << s.toString();
                sectionsList.push_front(s);

                searchString = matches.suffix();
            }
        }

        bool validateWholeInput(string input)
        {
            regex regexpInput(regexInput);
            smatch match;
            if (!regex_match(input, regexpInput))
            {
                cout << "Podany input nie jest zgodny ze spodziewanym formatem i nie mogl byc odczytany!\n";
                return false;
            }

            return true;
        }
    };

    class MaxLengthSectionFinder
    {
    public:
        Section* findBestSection(list<Section> sectionsList)
        {
            Section* best = NULL;
            for (list<Section>::iterator it = sectionsList.begin(); it != sectionsList.end(); ++it)
            {
                if (best->length < it->length)
                {
                    best = &*it;
                }
            }

            return best;
        }
    };

public:
    void execute()
    {
        string input = displayUsageAndAskForInput();

        ConsoleInputParser consoleParser;
        if (!consoleParser.parseInput(input))
        {
            return;
        }

        MaxLengthSectionFinder finder;
        Section* section = finder.findBestSection(consoleParser.getSectionList());
        cout << "Najdluzszy odcinek o dlugosci=" << section->length << " to " + section->toString();
    }

private:
    string displayUsageAndAskForInput()
    {
        cout << "Podaj odcinki w formacie [(x1,y1),(x2,y2)],...,[(xn-1,yn-1),(xn,yn)]\n";
        cout << "Przyklad dwoch docinkow podanych w takim formacie: [(1,1),(2,2)],[(1,3),(4,5)]\n";
        cout << "Podaj Twoj input\n";
        // string input; cin >> input;
        string input = "[(1,1),(23,2)],[(1,3),(4,5)],[(0,9),(8,6)],[(3,5),(7,3)]";
        cout << "\nTwoj input to " << input << "\n";

        return input;
    }
};

/*
Dana jest kwadratowa plansza o wymiarach N x N, na której znajduj¹ siê przeszkody. Po planszy
porusza siê budowniczy, pocz¹tkowo znajduj¹cy siê na pozycji (i, j). Budowniczy porusza siê wg
schematu: pierwszy ruch wykonuje w prawo, nastêpne w górê, w lewo i w dó³. W ka¿dym kierunku
porusza siê tak d³ugo, a¿ napotka przeszkodê albo koniec planszy. Po ka¿dym ruchu zostawia za sob¹
przeszkodê. Napisz funkcjê, która policzy, ile przeszkód zostawi³ budowniczy i wyznaczy jego now¹
pozycjê. Dodatkowo narysuj schemat blokowy tej funkcji
*/
class Exercise004
{
    class Position 
    {
    public:
        int x, y;
        void changePosition(int newX, int newY)
        {
            x = newX;
            y = newY;
        }
        string toStr()
        {
            return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
        }
    };
    class Board 
    {
        const char POSITION_BUILDER = 'b';
        const char POSITION_EMPTY = ' ';
        const char POSITION_OBSTACLE = 'o';
        int initialBoardSize;
        char** board;        
    public:
        Board(int initialBoardSize) : initialBoardSize(initialBoardSize)
        {            
            board = new char* [initialBoardSize];
            for (int i = 0; i < initialBoardSize; i++)
            {
                board[i] = new char[initialBoardSize];
                for (int j = 0; j < initialBoardSize; j++)
                {
                    board[i][j] = POSITION_EMPTY;
                }
            }
                
        }
        bool move(int x, int y, int newX, int newY)
        {            
            if (isPositionFree(newX, newY))
            {
                addObstacle(x, y);
                addBuilderPosition(newX, newY);
                return true;
            }
            return false;
        }
        bool isPositionFree(int x, int y)
        {
            
            int posX = x - 1;
            int posY = y - 1;
            if (posX < 0 || posX > initialBoardSize || posY < 0 || posY > initialBoardSize)
            {
                return false;
            }
            else if (board[posX][posY] == POSITION_EMPTY)
            {
                return true;
            }
            return false;            
        }
        void addBuilderPosition(int x, int y)
        {
            validatePosition(x, y);
            int posX = x - 1;
            int posY = y - 1;
            board[posX][posY] = POSITION_BUILDER;
        }
        void addObstacle(int x, int y)
        {    
            validatePosition(x, y);
            int posX = x - 1;
            int posY = y - 1;                       
            board[posX][posY] = POSITION_OBSTACLE;

        }
    private:
        void validatePosition(int x, int y)
        {
            int posX = x - 1;
            int posY = y - 1;
            if (posX < 0 || posX > initialBoardSize)
                throw std::logic_error("\nNiepoprawna pozycja x = " + std::to_string(x));
            else if (posY < 0 || posY > initialBoardSize)
                throw std::logic_error("\nNiepoprawna pozycja y = " + std::to_string(y));
            else if (board[posX][posY] == POSITION_OBSTACLE)
                throw std::logic_error("\nNa pozycji x = " + std::to_string(x) + "y = " + std::to_string(y) + "jest juz przeszkoda");
        }
    };
    class ConsoleInput 
    {                
        int boardSize;
    public:
        Position initialBuilderPosition;
        Board* board;
        void readInput() 
        {
            readBoardSize();
            readInitialPosition();
            readObstacles();
            
        }
    private:
       void readInitialPosition() 
        {                                
            cout << "\npodaj pozycje poczatkowa budowniczego: i = ";
            cin >> initialBuilderPosition.x;
            if (cin.fail())
            {
                throw std::logic_error("podano niepoprawna pozycje i.");
            }
            cout << ", j = ";
            cin >> initialBuilderPosition.y;
            if (cin.fail())
            {               
                throw std::logic_error("podano niepoprawna pozycje j.");
            } 
            board -> addBuilderPosition(initialBuilderPosition.x, initialBuilderPosition.y);
        }
       void readBoardSize()
       {
           int boardSize;
           cout << "Podaj rozmiar planszy: ";
           cin >> boardSize;
           cout << "\n";
           if (cin.fail())
           {
               throw std::logic_error("Podano niepoprawny rozmiar planszy.");
           }
           board = new Board(boardSize);
       }
       void readObstacles()
       {
           cout << "Podaj pozycje przeszkód, nacisnij 0 w dowolnym momencie jesli nie chcesz wprowadzac wiecej przeszkod.\n ";
           while (true)
           {
               int x, y;
               cout << "x = ";
               cin >> x;
               if (cin.fail())
               {
                   throw std::logic_error("Podano niepoprawny x.");
               }
               if (x == 0) break;
               cout << "y = ";
               cin >> y;
               if (cin.fail())
               {
                   throw std::logic_error("Podano niepoprawny y.");
               }
               if (y == 0) break;
               board -> addObstacle(x, y);
           }
       }
    };
public:
    void execute() 
    {
        ConsoleInput consoleInput;
        consoleInput.readInput(); 
        Board* board = consoleInput.board;
        Position pos = consoleInput.initialBuilderPosition;
        moveRight(board, pos);
        moveUp(board, pos);
        moveLeft(board, pos);
        moveDown(board, pos);
        cout << "Na koniec budowniczy jest na pozycji: " << pos.toStr();
    }
    void moveUp(Board* board, Position pos) 
    {
        while (move(board, pos, pos.x - 1, pos.y));
    }
    void moveLeft(Board* board, Position pos)
    {
        while (move(board, pos, pos.x, pos.y - 1));
    }
    void moveRight(Board* board, Position pos)
    {
        while (move(board, pos, pos.x, pos.y + 1));
    }
    void moveDown(Board* board, Position pos)
    {
        while (move(board, pos, pos.x + 1, pos.y));
    }
    bool move(Board* board, Position pos, int newX, int newY)
    {                   
            bool isMoved = board->move(pos.x, pos.y, newX, newY);
            if (!isMoved) return false;
            pos.changePosition(newX, newY);
            return true;
    }    
};

int main()
{
    try 
    {
        Exercise002 exercise002;
        Exercise003 exercise003;
        Exercise004 exercise004;

        cout << "Prosze podac numer zadania 2, 3, 4: ";
        int exerciseNo = 0;
        cin >> exerciseNo;
        switch (exerciseNo)
        {
        case 2:
            exercise002.execute();
            break;
        case 3:
            exercise003.execute();
            break;
        case 4:
            exercise004.execute();
            break;
        default:
            cout << "Niepoprawny numer zadania";
        }
        return 0;
    }
    catch (std::logic_error& e) 
    { 
        std::cout << e.what() << endl;
    }
}