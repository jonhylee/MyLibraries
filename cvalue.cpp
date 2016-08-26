
#include "cvalue.h"
#include <sstream>
#include <iomanip>
#include <math.h>

#define FLT_EPSILON __FLT_EPSILON__
#define CC_SAFE_DELETE(p)           do { delete (p); (p) = nullptr; } while(0)

const Value Value::Null;

#define MAX_ITOA_BUFFER_SIZE 256
double atof(const char* str)
{
    if (str == nullptr)
    {
        return 0.0;
    }
    
    char buf[MAX_ITOA_BUFFER_SIZE];
    strncpy(buf, str, MAX_ITOA_BUFFER_SIZE);
    
    // strip string, only remain 7 numbers after '.'
    char* dot = strchr(buf, '.');
    if (dot != nullptr && dot - buf + 8 <  MAX_ITOA_BUFFER_SIZE)
    {
        dot[8] = '\0';
    }
    
    return ::atof(buf);
}

Value::Value()
: _type(Type::NONE)
{
    memset(&_field, 0, sizeof(_field));
}

Value::Value(unsigned char v)
: _type(Type::BYTE)
{
    _field.byteVal = v;
}

Value::Value(int v)
: _type(Type::INTEGER)
{
    _field.intVal = v;
}

Value::Value(float v)
: _type(Type::FLOAT)
{
    _field.floatVal = v;
}

Value::Value(double v)
: _type(Type::DOUBLE)
{
    _field.doubleVal = v;
}

Value::Value(bool v)
: _type(Type::BOOLEAN)
{
    _field.boolVal = v;
}

Value::Value(const char* v)
: _type(Type::STRING)
{
    _field.strVal = new std::string();
    if (v)
    {
        *_field.strVal = v;
    }
}

Value::Value(const std::string& v)
: _type(Type::STRING)
{
    _field.strVal = new std::string();
    *_field.strVal = v;
}

Value::Value(const Value& other)
: _type(Type::NONE)
{
    *this = other;
}

Value::Value(Value&& other)
: _type(Type::NONE)
{
    *this = std::move(other);
}

Value::~Value()
{
    clear();
}

Value& Value::operator= (const Value& other)
{
    if (this != &other) {
        reset(other._type);

        switch (other._type) {
            case Type::BYTE:
                _field.byteVal = other._field.byteVal;
                break;
            case Type::INTEGER:
                _field.intVal = other._field.intVal;
                break;
            case Type::FLOAT:
                _field.floatVal = other._field.floatVal;
                break;
            case Type::DOUBLE:
                _field.doubleVal = other._field.doubleVal;
                break;
            case Type::BOOLEAN:
                _field.boolVal = other._field.boolVal;
                break;
            case Type::STRING:
                if (_field.strVal == nullptr)
                {
                    _field.strVal = new std::string();
                }
                *_field.strVal = *other._field.strVal;
                break;
            default:
                break;
        }
    }
    return *this;
}

Value& Value::operator= (Value&& other)
{
    if (this != &other)
    {
        clear();
        switch (other._type)
        {
            case Type::BYTE:
                _field.byteVal = other._field.byteVal;
                break;
            case Type::INTEGER:
                _field.intVal = other._field.intVal;
                break;
            case Type::FLOAT:
                _field.floatVal = other._field.floatVal;
                break;
            case Type::DOUBLE:
                _field.doubleVal = other._field.doubleVal;
                break;
            case Type::BOOLEAN:
                _field.boolVal = other._field.boolVal;
                break;
            case Type::STRING:
                _field.strVal = other._field.strVal;
                break;
            default:
                break;
        }
        _type = other._type;

        memset(&other._field, 0, sizeof(other._field));
        other._type = Type::NONE;
    }

    return *this;
}

Value& Value::operator= (unsigned char v)
{
    reset(Type::BYTE);
    _field.byteVal = v;
    return *this;
}

Value& Value::operator= (int v)
{
    reset(Type::INTEGER);
    _field.intVal = v;
    return *this;
}

Value& Value::operator= (float v)
{
    reset(Type::FLOAT);
    _field.floatVal = v;
    return *this;
}

Value& Value::operator= (double v)
{
    reset(Type::DOUBLE);
    _field.doubleVal = v;
    return *this;
}

Value& Value::operator= (bool v)
{
    reset(Type::BOOLEAN);
    _field.boolVal = v;
    return *this;
}

Value& Value::operator= (const char* v)
{
    reset(Type::STRING);
    *_field.strVal = v ? v : "";
    return *this;
}

Value& Value::operator= (const std::string& v)
{
    reset(Type::STRING);
    *_field.strVal = v;
    return *this;
}

bool Value::operator!= (const Value& v)
{
    return !(*this == v);
}
bool Value::operator!= (const Value& v) const
{
    return !(*this == v);
}

bool Value::operator== (const Value& v)
{
    const auto &t = *this;
    return t == v;
}
bool Value::operator== (const Value& v) const
{
    if (this == &v) return true;
    if (v._type != this->_type) return false;
    if (this->isNull()) return true;
    switch (_type)
    {
    case Type::BYTE:    return v._field.byteVal   == this->_field.byteVal;
    case Type::INTEGER: return v._field.intVal    == this->_field.intVal;
    case Type::BOOLEAN: return v._field.boolVal   == this->_field.boolVal;
    case Type::STRING:  return *v._field.strVal   == *this->_field.strVal;
    case Type::FLOAT:   return fabs(v._field.floatVal  - this->_field.floatVal)  <= FLT_EPSILON;
    case Type::DOUBLE:  return fabs(v._field.doubleVal - this->_field.doubleVal) <= FLT_EPSILON;
    default:
        break;
    };

    return false;
}

/// Convert value to a specified type
unsigned char Value::asByte() const
{
    if (_type == Type::BYTE)
    {
        return _field.byteVal;
    }

    if (_type == Type::INTEGER)
    {
        return static_cast<unsigned char>(_field.intVal);
    }

    if (_type == Type::STRING)
    {
        return static_cast<unsigned char>(atoi(_field.strVal->c_str()));
    }

    if (_type == Type::FLOAT)
    {
        return static_cast<unsigned char>(_field.floatVal);
    }

    if (_type == Type::DOUBLE)
    {
        return static_cast<unsigned char>(_field.doubleVal);
    }

    if (_type == Type::BOOLEAN)
    {
        return _field.boolVal ? 1 : 0;
    }

    return 0;
}

int Value::asInt() const
{
    if (_type == Type::INTEGER)
    {
        return _field.intVal;
    }

    if (_type == Type::BYTE)
    {
        return _field.byteVal;
    }

    if (_type == Type::STRING)
    {
        return atoi(_field.strVal->c_str());
    }

    if (_type == Type::FLOAT)
    {
        return static_cast<int>(_field.floatVal);
    }

    if (_type == Type::DOUBLE)
    {
        return static_cast<int>(_field.doubleVal);
    }

    if (_type == Type::BOOLEAN)
    {
        return _field.boolVal ? 1 : 0;
    }

    return 0;
}

float Value::asFloat() const
{
    if (_type == Type::FLOAT)
    {
        return _field.floatVal;
    }

    if (_type == Type::BYTE)
    {
        return static_cast<float>(_field.byteVal);
    }

    if (_type == Type::STRING)
    {
        return atof(_field.strVal->c_str());
    }

    if (_type == Type::INTEGER)
    {
        return static_cast<float>(_field.intVal);
    }

    if (_type == Type::DOUBLE)
    {
        return static_cast<float>(_field.doubleVal);
    }

    if (_type == Type::BOOLEAN)
    {
        return _field.boolVal ? 1.0f : 0.0f;
    }

    return 0.0f;
}

double Value::asDouble() const
{
    if (_type == Type::DOUBLE)
    {
        return _field.doubleVal;
    }

    if (_type == Type::BYTE)
    {
        return static_cast<double>(_field.byteVal);
    }

    if (_type == Type::STRING)
    {
        return static_cast<double>(atof(_field.strVal->c_str()));
    }

    if (_type == Type::INTEGER)
    {
        return static_cast<double>(_field.intVal);
    }

    if (_type == Type::FLOAT)
    {
        return static_cast<double>(_field.floatVal);
    }

    if (_type == Type::BOOLEAN)
    {
        return _field.boolVal ? 1.0 : 0.0;
    }

    return 0.0;
}

bool Value::asBool() const
{
    if (_type == Type::BOOLEAN)
    {
        return _field.boolVal;
    }

    if (_type == Type::BYTE)
    {
        return _field.byteVal == 0 ? false : true;
    }

    if (_type == Type::STRING)
    {
        return (*_field.strVal == "0" || *_field.strVal == "false") ? false : true;
    }

    if (_type == Type::INTEGER)
    {
        return _field.intVal == 0 ? false : true;
    }

    if (_type == Type::FLOAT)
    {
        return _field.floatVal == 0.0f ? false : true;
    }

    if (_type == Type::DOUBLE)
    {
        return _field.doubleVal == 0.0 ? false : true;
    }

    return false;
}

std::string Value::asString() const
{

    if (_type == Type::STRING)
    {
        return *_field.strVal;
    }

    std::stringstream ret;

    switch (_type)
    {
        case Type::BYTE:
            ret << _field.byteVal;
            break;
        case Type::INTEGER:
            ret << _field.intVal;
            break;
        case Type::FLOAT:
            ret << std::fixed << std::setprecision( 7 )<< _field.floatVal;
            break;
        case Type::DOUBLE:
            ret << std::fixed << std::setprecision( 16 ) << _field.doubleVal;
            break;
        case Type::BOOLEAN:
            ret << (_field.boolVal ? "true" : "false");
            break;
        default:
            break;
    }
    return ret.str();
}

static std::string getTabs(int depth)
{
    std::string tabWidth;

    for (int i = 0; i < depth; ++i)
    {
        tabWidth += "\t";
    }

    return tabWidth;
}

static std::string visit(const Value& v, int depth)
{
    std::stringstream ret;

    switch (v.getType())
    {
        case Value::Type::NONE:
        case Value::Type::BYTE:
        case Value::Type::INTEGER:
        case Value::Type::FLOAT:
        case Value::Type::DOUBLE:
        case Value::Type::BOOLEAN:
        case Value::Type::STRING:
            ret << v.asString() << "\n";
            break;
        default:
            break;
    }

    return ret.str();
}

std::string Value::getDescription() const
{
    std::string ret("\n");
    ret += visit(*this, 0);
    return ret;
}

void Value::clear()
{
    // Free memory the old value allocated
    switch (_type)
    {
        case Type::BYTE:
            _field.byteVal = 0;
            break;
        case Type::INTEGER:
            _field.intVal = 0;
            break;
        case Type::FLOAT:
            _field.floatVal = 0.0f;
            break;
        case Type::DOUBLE:
            _field.doubleVal = 0.0;
            break;
        case Type::BOOLEAN:
            _field.boolVal = false;
            break;
        case Type::STRING:
            CC_SAFE_DELETE(_field.strVal);
            break;
        default:
            break;
    }
    
    _type = Type::NONE;
}

void Value::reset(Type type)
{
    if (_type == type)
        return;

    clear();

    // Allocate memory for the new value
    switch (type)
    {
        case Type::STRING:
            _field.strVal = new std::string();
            break;
        default:
            break;
    }

    _type = type;
}

