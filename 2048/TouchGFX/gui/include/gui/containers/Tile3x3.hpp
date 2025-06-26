#ifndef TILE3X3_HPP
#define TILE3X3_HPP

#include <gui_generated/containers/Tile3x3Base.hpp>

class Tile3x3 : public Tile3x3Base
{
public:
    Tile3x3();
    virtual ~Tile3x3() {}
    void setValue(uint16_t value);
    virtual void initialize();
    uint16_t getValue() const;
protected:
};

#endif // TILE3X3_HPP
