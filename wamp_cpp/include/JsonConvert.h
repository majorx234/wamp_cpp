
#ifndef JSONCONVERT_H_
#define JSONCONVERT_H_

#include <functional>
#include <vector>

#include <json/json.h>

typedef std::function<Json::Value(std::vector<Json::Value>)> RemoteProcedure;

template<class T>
T convertJson(Json::Value& val)
{
  return T();
}

template<>
float convertJson<float>(Json::Value& val);

template<>
int convertJson<int>(Json::Value& val);

template<>
std::string convertJson<std::string>(Json::Value& val);

template<>
bool convertJson<bool>(Json::Value& val);

template<>
Json::Value convertJson<Json::Value>(Json::Value& val);

#endif //JSONCONVERT_H_