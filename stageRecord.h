#pragma once

class StageRecord
{
public:
	static StageRecord* GetInstance()
	{
		static StageRecord record;
		return &record;
	}

	void SetLevel(char a)
	{
		level = a;
	}

	char GetLevel()
	{
		return level;
	}
	void SetstNum(char a)
	{
		stNum = a;
	}

	char GetstNum()
	{
		return stNum;
	}



private:
	char level;
	char stNum;

	StageRecord()
	{
		level = '1';
		stNum = '1';
	}
};