#include <iostream>
using namespace std;

class CNetworkConnector
{
public:
	CNetworkConnector(int& result)
	{
		result = OnConnect();
	}

	virtual ~CNetworkConnector(void)
	{
		OnDisConnect ();
	}

public:
	virtual int TransmitData(const char* data)
	{
		bool success = true;
		//some logic

		return success?0:-1;
	}

protected:
	virtual int OnConnect () { cout<<"base OnConnect()"<<endl; return -1;}
	virtual int OnDisConnect () { return -1;}

private:
	char m_buffer [1024];
};

class C3GNetworkConnector : public CNetworkConnector
{
public:
	C3GNetworkConnector(int& result) : CNetworkConnector(result)
	{

	}

	virtual ~C3GNetworkConnector(void) {}

	void PrintData ()
	{

	}

protected:
	virtual int OnConnect ()
	{
		bool success = true;
		//some logic
		return success?0:-1;
	}

	virtual int OnDisConnect ()
	{
		//some logic
		return 0;
	}
};

class CWifiNetworkConnector : public CNetworkConnector
{
public:
	CWifiNetworkConnector(int& result) : CNetworkConnector(result)
	{

	}
	virtual ~CWifiNetworkConnector(void) {}

protected:
	virtual int OnConnect ()
	{
		bool success = true;
		//some logic
		return success?0:-1;
	}

	virtual int OnDisConnect ()
	{
		//some logic
		return 0;
	}
};

int main(int argc, char* argv[])
{
	int result;
	CNetworkConnector* pNetworkConnector = 0;
	pNetworkConnector = new C3GNetworkConnector(result);
	if (result)
	{
		pNetworkConnector = new CWifiNetworkConnector(result);
		if (result)
		{
			return -1;
		}
		result = pNetworkConnector->TransmitData(("test"));
	}
	else
	{
		result = pNetworkConnector->TransmitData(("test"));
		if (result == 0)
		{
			//pNetworkConnector->PrintData();
		}
	}

	return 0;
}
