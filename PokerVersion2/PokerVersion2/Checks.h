#ifndef CHECKS_H
#define CHECKS_H


class Checks
{
public:

	vector<int> determineValues;
	vector<char> determineSuits;
	vector<int> test;

	int ispair(vector<int> determineValues);
	int flush(vector<char> determineSuits);
	int straight(vector<int> determineValues);
	int threeofakind(vector<int> determineValues);
	int fourofakind(vector<int> determineValues);
	int fullhouse(vector<int> determineValues);
	int FindHighCard(vector<string>,vector<string>);
	int DetermineHand(vector<int >values, vector<char>suits);
	//int determinecpuhand(vector<int> cvalues, vector<char>csuits);
	void determine(int PlayerHandValue, int CpuHandValue,string,int,int,int,vector<string>,vector<string>);
	void FoldValue(bool,int,int,int,int);
	void FoldValueC(bool,int,int,int,int);
	string handText(int);
	Checks();
};

#endif