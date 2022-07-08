//Erkin Aydın 22002956
#include <string>
using namespace std;

class Chemical{
public:
    Chemical();
    Chemical( int id, string type);
    int getId();
    void setId( int id);
    void setType( string type);
    string getType();
    int getCombustiveDegree();
    void increaseDegree();
    void decreaseDegree();
    bool  isChemCombustive();
    bool isPlaceCombustive();

private:
    int id;
    string type;
    int combustiveDegree;
};
