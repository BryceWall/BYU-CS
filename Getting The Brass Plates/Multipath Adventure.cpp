#include <iostream>                                         //Libraries used in this program
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void PrintIntroductoryMessage();                            //All prototypes (l.8-22) are used below and represent a
void LabanEncounter1();                                     //specific point in the story.
void LabanArmyStatement();
void DishonorStatement();
void LabanArmyVsNephiArmy();
void LabanArmyAttack(const string& weapon, int numNephiArmy);
void IWillGoAndDo();
void WentToBabylon();
void LabanEncounter2();
void RunFromCity();
void NephiGetsPlates();
void NephiReturnsHome();
void TryAgain();
int BattleScene(int numLabanArmy,int numNephiArmy, const string& labanWeapon, const string& WEAPON);
string EndMessage();


int main() {
    string play;

    cout << "Do you want to play Nephi's Brass Plate Adventure?" << endl;
    cout << R"((Type the word "Yes" to play, or any other key to exit.))" << endl;

    cin >> play;
    cin.ignore();

    while(play == "Yes"){
        PrintIntroductoryMessage();                      //Beginning function called to introduce story and start adventure
    }
    return 0;
}

void PrintIntroductoryMessage() {

    string userAnswer;

    cout << "Your name is Nephi. You and your brothers have been sent by the Lord and your father Lehi " << endl;
    cout << "to go to Jerusalem and get the brass plates from Laban. " << endl;
    cout << "You enter the city and have two choices:" << endl;
    cout << "-Go to laban" << endl;
    cout << "-Stay in the city" << endl;
    cout << R"((Type the word "Go" or "Stay" for your answer))" << endl;        //Gives option for user to select
    getline(cin, userAnswer);                                            //several beginning paths

    if(userAnswer == "Go"){
        LabanEncounter1();                  //takes user to first encounter and second if/then statement
    }
    else if(userAnswer == "Stay") {
        DishonorStatement();                //prints message that ends the game with return value 0.
    }
    else if( userAnswer == "exit(0)"){      //Allows for user to exit code
        cout << EndMessage();
    }
    else {                                  //gives user a second chance to provide a valid input without exiting code
        cout << "You entered an invalid answer. Check your spelling and capital letter." << endl;
        PrintIntroductoryMessage();
    }
}

void LabanEncounter1() {

    string userAnswer;

    cout << "Your brother Laman chooses to go to Laban and after talking with Laban, ";
    cout << "he is cast out and threatened for his life." << endl;
    cout << "Laman comes back and tells you the news." << endl;
    cout << "You have three choices:" << endl;
    cout << "-Run away" << endl;
    cout << "-Go in with your army of 4, swords blazing and battle for the plates" << endl;
    cout << "-Get everything you own to barter" << endl;
    cout << R"((Type the word "Run", "Go", or "Get" for your answer.))" << endl;
    getline(cin, userAnswer);

    if (userAnswer == "Run"){
        DishonorStatement();                  //prints message that ends the game with return value  0.
    }
    else if(userAnswer == "Go"){
        LabanArmyStatement();                 //Prints message about Laban's army
        LabanArmyVsNephiArmy();               //takes user to a function that prompts user for input on a battle
        cout << endl;                         // end message is printed, ending game with return value 0;
    }
    else if(userAnswer == "Get"){
        IWillGoAndDo();                    //takes user on next point in adventure
    }
    else if( userAnswer == "exit(0)"){      //Allows for user to exit code
        cout << EndMessage();
    }
    else {                                 //gives user a second chance to provide a valid input without exiting code
        cout << "You entered an invalid answer. Check your spelling and capital letter." << endl;
        LabanEncounter1();
    }
}
void LabanArmyStatement(){                  //referenced above
    cout << "\"Behold he is a mighty man, and he can command fifty, ";
    cout << "yea, even he can slay fifty; then why not us?\"" << endl;
    cout << endl;
}

void DishonorStatement(){                   //referenced throughout the program
    cout << "God and your father are disappointed. \"Dishonor on your whole family. ";
    cout << "Dishonor on you! Dishonor on your cow!\"" << endl;
    TryAgain();
}

string EndMessage(){                       //end message is referenced throughout the program and returns value 0 at end

    return "The End.";
}

void TryAgain(){                            //Gives user a chance to try game again if they took a wrong path

    string userAnswer;

    cout << "Do you want to start over?" << endl;
    cout << "You have two choices:" << endl;
    cout << "-Start again" << endl;
    cout << "-No thanks" << endl;
    cout << R"((Type the word "Start", or "No" for your answer.))" << endl;

    getline(cin, userAnswer);

    if(userAnswer == "Start"){
        PrintIntroductoryMessage();         //Starts new game at introductory statement
    }
    else if(userAnswer == "No"){
        cout << EndMessage();
    }
    else{                                  //gives user a second chance to provide a valid input without exiting code
        cout << "You entered an invalid answer. Check your spelling and capital letter." << endl;
        TryAgain();
    }
}

void LabanArmyVsNephiArmy(){                //referenced above and receives input from user about a battle and
    string item;                            //tells user they have lost and ends the game in the function
    int numPeople = 0;                      //this function is called into

    cout << "What item(s) will you choose to defend yourself against Laban's army?" << endl;
    getline(cin,item);
    cout << endl;

    cout << "How many people are with you?" << endl;
    cin >> numPeople;
    cin.ignore();
    cout << endl;

    LabanArmyAttack(item,numPeople);        //code references inputs and passes them into next function block
}

void LabanArmyAttack(string const& WEAPON, int numNephiArmy){     //referenced directly above
    srand(time(nullptr));           //Random function with a seed of time and null value for randomness
    int numLabanArmy = (rand()%50)+1;           //Randomly assigns a value between 1-50 for the army size
    string labanWeapon[4];                      //Weapon array referenced below
    int randomWeapon = (rand()%4);              //Randomly selects a value out of numbers 0-3

    labanWeapon[0] = "Swords";              //line 162-165 are elements of an array assigned to weapon options
    labanWeapon[1] = "Fish";
    labanWeapon[2] = "Spears";
    labanWeapon[3] = "Bananas";

    cout << "You chose to attack Laban's army with: " << numNephiArmy << " warriors using " << WEAPON << endl;
    cout << endl;
    cout << "Laban's army has: " << numLabanArmy << " warriors using " << labanWeapon[randomWeapon] << endl;
    cout << endl;                        //Laban's army weapon is selected ^^ with a random value in the array index

    BattleScene(numLabanArmy,numNephiArmy, labanWeapon[randomWeapon], WEAPON);      //Calls Battle scene function

}

int BattleScene(int numLabanArmy,int numNephiArmy, const string& labanWeapon, const string& WEAPON){

    int tempVal = 0;                            //Temporary value to hold value of another variable
    int labanArmyVal = 0;
    int nephiArmyVal = 0;
    const int NUM_STAGES = 5;

    cout << "The battle with Laban's army will commence in 5 stages or until one army defeats the other." << endl;
    cout << "Your army has : " << numNephiArmy << " warriors." << endl;
    cout << "Laban's army has: " << numLabanArmy << " warriors." << endl;
    cout << endl;

    labanArmyVal = numLabanArmy;            //Assigns original value of NumLabanArmy to LabanArmyVal to hold it
    nephiArmyVal = numNephiArmy;            //Assigns original value of NumNephiArmy to NephiArmyVal to hold it

    for(int i = 0; i < NUM_STAGES; i++){            //For loop to simulate rounds or stages of a battle

        cout << "Stage: " << i+1 << endl;           //Outputs the index+1 to give a real number i.e (0+1 = stage 1)
        cout << "Your army has: " << numNephiArmy << " warriors." << endl;
        cout << "Laban's army has: " << numLabanArmy << " warriors." << endl;
        cout << endl;

        if(numLabanArmy == numNephiArmy){           //If the armies are the same size, 5 people are subtracted from
            numLabanArmy = (numLabanArmy-5);        // Laban's army to give advantage to Nephi's army
        }

        tempVal = numNephiArmy;                     //simulates a battle where each team has 1/3 of the opposing
        numNephiArmy -= numLabanArmy/3;             // team's current size subtracted from their army
        numLabanArmy -= tempVal/3;                  // armies become smaller each initialization of the for loop

        system("pause");                  //Creates a pause in the for loop to keep the user engaged

        if(numNephiArmy <= 0){                      //if Nephi or Laban's armies are less than 0, the loop is broken
            break;
        }
        if(numLabanArmy <= 0){
            break;
        }
    }

    if(numNephiArmy < 0){                      //If Nephi or Laban's army is less than 0 at the end of the loop,
        numNephiArmy = 0;                      //the final value of the army is initialized to 0
    }                                          //(you can't have a negative amount of people)
    if(numLabanArmy < 0){
        numLabanArmy = 0;
    }
    if( numLabanArmy > numNephiArmy){           //if nephi's army at the end is less than laban's, the game is over
        cout << "Your army of " << nephiArmyVal << " was slain by Laban's army of " << labanArmyVal << endl;
        cout << endl;
        TryAgain();
    }
    else if(numNephiArmy > numLabanArmy){       //If Nephi's army is greater than Laban's the next leg is initialized
        cout << "You defeated Laban's army of " << labanArmyVal << " with your army of " << nephiArmyVal << endl;
        cout << endl;
        cout << "You go to Laban's house and get the plates from Zoroam who is frightfully willing to give them to you";
        cout << endl;

        NephiReturnsHome();                     //References the last message function saying that Nephi got the plates
    }

    return 0;
}

void IWillGoAndDo(){                          //next leg in journey

    string userAnswer;

    cout << "Your brothers are upset with you and begin to murmur, but they go along with you to get your gold. " << endl;

    cout << endl;
    system("pause");                //creates pause in function for style and to create whitespace
    cout << endl;

    cout << "Laman and Lemuel tell you that you should take the treasure ";
    cout << "and start a new life with them down the road in Babylon." << endl;
    cout << "You have two choices:" << endl;
    cout << "-Go with them to Babylon" << endl;
    cout << "-\"Do what the Lord commands\" and go to Laban for the plates" << endl;
    cout << R"((Type the word "Go", or "Do" for your answer.))" << endl;

    getline(cin, userAnswer);
    cout << endl;

    if(userAnswer == "Go"){
        WentToBabylon();                    //takes user down path that leads to an ending point returning 0
    }
    else if(userAnswer == "Do"){
        LabanEncounter2();                  //takes user to next decision point
    }
    else if( userAnswer == "exit(0)"){      //Allows for user to exit code
        cout << EndMessage();
    }
    else {                                  //gives user a second chance to provide a valid input without exiting code
        cout << "You entered an invalid answer. Check your spelling and capital letter." << endl;
        IWillGoAndDo();
    }
}

void WentToBabylon(){                           //referenced above ending with return 0
    cout << "1 Nephi 10:3 \"... they should be destroyed, even that great city Jerusalem,";
    cout << "and many be carried away captive into Babylon.\"" << endl;
    cout << endl;

    cout << "You died spiritually and probably literally too.";
    TryAgain();
}

void LabanEncounter2(){                         //referenced above and is used to give user next decision point

    string userAnswer;

    cout << "Laban wants your treasure so he sends his guards after you to kill you, and he steals your treasure." << endl;
    cout << "You have two choices:" << endl;
    cout << "-Run away" << endl;
    cout << "-Try and take back your treasure" << endl;
    cout << R"((Type the word "Run", or "Take" for your answer.))" << endl;

    getline(cin, userAnswer);

    if(userAnswer == "Run"){
        RunFromCity();                          //takes user down next path to next decision point
    }
    else if(userAnswer == "Take"){
        cout << "Laban's guards catch you." << endl;
        LabanArmyStatement();                   //prints statement about army and ends path with return 0
        cout << "Laban slays you." << endl;
        TryAgain();
    }
    else if( userAnswer == "exit(0)"){          //Allows for user to exit code
        cout << EndMessage();
    }
    else {                                      //gives user a second chance to provide a valid input without exiting code
        cout << "You entered an invalid answer. Check your spelling and capital letter." << endl;
        LabanEncounter2();
    }
}

void RunFromCity(){                             //user is given story to read with pause for style

    string userAnswer;

    cout << "You make it out of the city alive but without gold or the plates ";
    cout << "which makes Laman and Lemuel very mad." << endl;

    cout << endl;
    system("pause");                    //pause for style and whitespace in output

    cout << "They start hitting you with a rod until an angel comes and commands them to stop and have faith." << endl;
    cout << "The angel commands you to return to get the plates." << endl;
    cout << "Laman and Lemuel murmur again, but agree to return." << endl;

    cout << endl;
    system("pause");                    //pause for style and whitespace in output

    cout << "You return to the city, and are led by the Spirit through the city until you find Laban ";
    cout << "drunk and asleep on the ground." << endl;
    cout << "The angel tells you to slay Laban." << endl;
    cout << "You have two choices:" << endl;
    cout << "-Slay laban and take his clothing" << endl;
    cout << "-Shy away and don't get the plates" << endl;
    cout << R"((Type the word "Slay", or "Shy" for your answer.))" << endl;

    getline(cin, userAnswer);

    if(userAnswer == "Slay"){
        NephiGetsPlates();                  //prints victory statements and ends the game with return 0
    }
    else if(userAnswer == "Shy"){
        DishonorStatement();                //prints dishonor statement and ends with return 0
        cout << endl;
        TryAgain();
    }
    else if( userAnswer == "exit(0)"){      //Allows for user to exit code
        cout << EndMessage();
    }
    else {                                  //gives user a second chance to provide a valid input without exiting code
        cout << "You entered an invalid answer. Check your spelling and capital letter." << endl;
        RunFromCity();
    }
}

void NephiGetsPlates() {                     //victory statements given at the end of the game for correct paths chosen
    cout << "Since you are in Laban's clothes, Zoroam mistakes you for Laban and gives you the plates." << endl;
    cout << "You go with Zoroam to the walls of the city and your brothers are afraid that Laban slew you." << endl;
    cout << "You call for them and reunite with your brothers, and convince Zoroam to leave Jerusalem with you."
         << endl;

    cout << endl;
    system("pause");               //pause for style and whitespace in output

    NephiReturnsHome();
}

void NephiReturnsHome(){                        //New function to print out the final string statement of the game
    cout << "You return home to your parents, \"And it came to pass that after we had come down ";
    cout << "into the wilderness unto our father behold, he was filled with joy, " << endl;
    cout << "and also my mother, Sariah, was exceedingly glad, for she truly had mourned because of us." << endl;

    cout << endl;
    system("pause");                //pause for style and whitespace in output

    cout << "\"Well done, thou good and faithful servant: thou has been faithful over a few things," << endl;
    cout << " I will make thee ruler over many things: enter thou into the joy of thy Lord.\"" << endl;
    cout << endl;

    TryAgain();                     //prints end message with return 0
}