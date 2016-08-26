
#ifndef __BLACK_CVALUE__
#define __BLACK_CVALUE__

#include <string>
#include <vector>

/*
 * This class is provide as a wrapper of basic types, such as int and bool.
 */
class Value
{
public:
    /** A predefined Value that has not value. */
    static const Value Null;

    /** Default constructor. */
    Value();
    
    /** Create a Value by an unsigned char value. */
    explicit Value(unsigned char v);
    
    /** Create a Value by an integer value. */
    explicit Value(int v);
    
    /** Create a Value by a float value. */
    explicit Value(float v);
    
    /** Create a Value by a double value. */
    explicit Value(double v);
    
    /** Create a Value by a bool value. */
    explicit Value(bool v);
    
    /** Create a Value by a char pointer. It will copy the chars internally. */
    explicit Value(const char* v);
    
    /** Create a Value by a string. */
    explicit Value(const std::string& v);

    /** Create a Value by another Value object. */
    Value(const Value& other);
    /** Create a Value by a Value object. It will use std::move internally. */
    Value(Value&& other);
    
    /** Destructor. */
    ~Value();

    /** Assignment operator, assign from Value to Value. */
    Value& operator= (const Value& other);
    /** Assignment operator, assign from Value to Value. It will use std::move internally. */
    Value& operator= (Value&& other);

    /** Assignment operator, assign from unsigned char to Value. */
    Value& operator= (unsigned char v);
    /** Assignment operator, assign from integer to Value. */
    Value& operator= (int v);
    /** Assignment operator, assign from float to Value. */
    Value& operator= (float v);
    /** Assignment operator, assign from double to Value. */
    Value& operator= (double v);
    /** Assignment operator, assign from bool to Value. */
    Value& operator= (bool v);
    /** Assignment operator, assign from char* to Value. */
    Value& operator= (const char* v);
    /** Assignment operator, assign from string to Value. */
    Value& operator= (const std::string& v);

    /** != operator overloading */
    bool operator!= (const Value& v);
    /** != operator overloading */
    bool operator!= (const Value& v) const;
    /** == operator overloading */
    bool operator== (const Value& v);
    /** == operator overloading */
    bool operator== (const Value& v) const;

    /** Gets as a byte value. Will convert to unsigned char if possible, or will trigger assert error. */
    unsigned char asByte() const;
    /** Gets as an integer value. Will convert to integer if possible, or will trigger assert error. */
    int asInt() const;
    /** Gets as a float value. Will convert to float if possible, or will trigger assert error. */
    float asFloat() const;
    /** Gets as a double value. Will convert to double if possible, or will trigger assert error. */
    double asDouble() const;
    /** Gets as a bool value. Will convert to bool if possible, or will trigger assert error. */
    bool asBool() const;
    /** Gets as a string value. Will convert to string if possible, or will trigger assert error. */
    std::string asString() const;

    /**
     * Checks if the Value is null.
     * @return True if the Value is null, false if not.
     */
    inline bool isNull() const { return _type == Type::NONE; }

    /** Value type wrapped by Value. */
    enum class Type
    {
        /// no value is wrapped, an empty Value
        NONE = 0,
        /// wrap byte
        BYTE,
        /// wrap integer
        INTEGER,
        /// wrap float
        FLOAT,
        /// wrap double
        DOUBLE,
        /// wrap bool
        BOOLEAN,
        /// wrap string
        STRING
    };

    /** Gets the value type. */
    inline Type getType() const { return _type; }

    /** Gets the description of the class. */
    std::string getDescription() const;

private:
    void clear();
    void reset(Type type);

    union
    {
        unsigned char byteVal;
        int intVal;
        float floatVal;
        double doubleVal;
        bool boolVal;

        std::string* strVal;
    }_field;

    Type _type;
};

#endif
