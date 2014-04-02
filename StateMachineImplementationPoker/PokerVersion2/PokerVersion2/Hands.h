#ifndef HANDS_H
#define HANDS_H


class Hands
{
public:
	void createdeck(vector<string>& deck);
	void playercard(vector<string>& deck);
	void cpucard(vector<string>&deck);
	void tablecards(vector<string>& deck, int x); 
	vector<string> completeHand(vector<string> tablehand, vector<string> passedHand);
	vector<int> handValue(vector<string> passedHand);
	vector<char> getSuit(vector<string>passedHand);
};

#endif