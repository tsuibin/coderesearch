#include <algorithm>

#include <iostream>

#include <iterator>

#include <ostream>

#include <string>

#include <vector>



// Sort lines of text.

int main(  )

{

	using namespace std;

	string line;

	vector<string> data;

	while (getline(cin, line))

		data.push_back(line);

	sort(data.begin(  ), data.end(  ));

	copy(data.begin(  ), data.end(  ),

			ostream_iterator<string>(cout, "\n"));

}

