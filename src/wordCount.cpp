#include <fstream>
#include <cmath>
#include <map>

/**
    Function to check the amount of parameters given to the file.
    @param  t_amountOfParams the amount of params given to the file.
*/
void checkParams(int t_amountOfParams);

/**
    Function to check if a character is allowed to be counted of not.
    @param  t_character The character you want to check.
    @return  True if it is valid, false if not.
*/
bool isCharacterValid(char t_character);

/**
    Function to create a map of the characters and their occurences.
    @param  t_path A path of the file that you count the characters of.
    @return  A map of the characters and their counters.
*/
std::map<char, int> countCharacters(std::string t_path);

/**
    Function to invert the map keys and values.
    @param  t_inputMap The map created in countCharacters().
    @return  A map of the counters and the characters.
*/
std::map<int, char> invertMap(std::map<char,int>& t_inputMap);

/**
    Function to print a "graph" of the vaues in the inverted map.
    @param  t_inputMap The map created in invertMap(). 
*/
void graphMap(std::map<int, char>& t_intputMap);

/**
    Function to calculate the largest amount in the map of letters.
    @param t_inputMap  The map created in invertMap().
    @return  The largest amount in the map.
*/
int calculateLargestAmount(std::map<int, char>& t_inputMap);

int main(int argc, char* argv[])
{	
    checkParams(argc);

    std::printf("This is the letter count for %s: \n", argv[1]);

    // Call the countCharacters function on argv[1] which is the file.
    std::map<char, int> normalMap = countCharacters(argv[1]);

    // Call the invertMap function on the countCharacters map above.
    std::map<int, char> invertedMap = invertMap(normalMap);

    // Call the graphMap function to print a "graph" of the results.
    graphMap(invertedMap);
    return 0;
}

void checkParams(const int t_amountOfParams)
{
    if (t_amountOfParams == 1)
    {
        std::printf("Please enter a file name.\n");
        exit(1);
    }
}

bool isCharacterValid(const char t_character)
{
    // Use the standard isalpha() function to check if it is a letter.
    return std::isalpha(t_character) ? true : false;
}

std::map<char, int> countCharacters(const std::string t_filepath) 
{
	char character;
	
    // This is the map we are going to return.
	std::map<char, int> outputMap;
	
    // This is the input stream we use to get all the character numbers.
	std::ifstream inputStream(t_filepath);
	
    // While loop until there are no more characters left in the input stream.
	while (inputStream.get(character))
	{
		character=toupper(character);
	    if (isCharacterValid(character))
        {
            if (!(outputMap.count(character)))
            {
                // If the character is not in the output map
                // set the value to 0.
                outputMap[character] = 0;
            }
            outputMap[character] += 1;
        }
	}
	// Close the stream of characters.
	inputStream.close();
	return outputMap;
}

std::map<int, char> invertMap(std::map<char,int>& t_inputMap)
{
	std::map<int, char> outputMap;
	
    // Create an iterator for the input map, flipping the keys and values. 
	for (const auto& pair : t_inputMap)
	{
		outputMap[pair.second] = pair.first;
	}
	return outputMap;
}

void graphMap(std::map<int, char>& t_inputMap)
{	
    int amountOfStars;
    int largestAmount = calculateLargestAmount(t_inputMap);

	// Loop through the pairs in the map given in the parameters
	for (const auto& pair : t_inputMap)
	{
		// Calculate the amount of stars that need to be printed for this pair.
		amountOfStars = lround(pair.first*100/largestAmount);

		// Print the beginning half of the line with the letter.
		std::printf("%c > %-6d | ", pair.second, pair.first);

		// Create a loop that prints a star amountOfStars times.
	    for (int i = 0; i < amountOfStars; i++) 
		{
			std::printf("-");
		}
		// End the line to prepare for a new pair.
		std::printf("\n");
	}
}

int calculateLargestAmount(std::map<int, char>& t_inputMap) 
{
    // Get the last pair in the map using an iterator.
    int amount = (--t_inputMap.end())->first;
    return amount;
}
