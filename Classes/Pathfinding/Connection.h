#ifndef CONNECTION_H
#define CONNECTION_H

#include <string>
#include "../Utils/Utils.h"

/// Connection Class
class Connection {
	public:
        Connection (int from ,int to, float cost);
        Connection ();

        float getCost();
        int getFromNode();
        int getToNode();
        void setValid(bool val);
        bool getValid();
        std::string get_Str();

    private:
        int _fromNode;
        int _toNode;
        float _cost;
        bool _valid;
};

#endif
