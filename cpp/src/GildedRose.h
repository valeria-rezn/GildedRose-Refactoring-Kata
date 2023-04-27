#include <string>
#include <vector>

using namespace std;

class Item
{
public:
    string name;
    int sellIn;
    int quality;
    Item(string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality)
    {}
};

class GildedRose
{
public:
   
    vector<Item>& items;
    GildedRose(vector<Item>& items);
    enum ItemType
    {
        ITEM_NORMAL,
        ITEM_AGED_BRIE,
        ITEM_SULFURAS,
        ITEM_BACKSTAGE_PASSES,
        ITEM_CONJURED
    };
    void updateQuality();
    void updateQualityAgedBrie(int index);
    void updateQualityBackstagePasses(int index);
    void updateQualityConjured(int index);
    void updateQualitySulfuras(int index);
    void updateQualityNormal(int index);
private:
    ItemType getItemTypeByName(const string& name);
};
