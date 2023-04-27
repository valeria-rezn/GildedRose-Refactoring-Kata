#include "GildedRose.h"
#include "iostream"

const int MIN_QUALITY = 0;
const int MAX_QUALITY = 50;
const string AG_BR = "Aged Brie";
const string SULFURAS = "Sulfuras, Hand of Ragnaros";
const string BACKST_PS = "Backstage passes to a TAFKAL80ETC concert";
const string CONJURED = "Conjured Mana Cake";


GildedRose::GildedRose(vector<Item>& items) : items(items)
{}

GildedRose::ItemType GildedRose::getItemTypeByName(const string& name)
{
    if (name == AG_BR) {
        return ITEM_AGED_BRIE;
    }
    else if (name == SULFURAS) {
        return ITEM_SULFURAS;
    }
    else if (name == BACKST_PS) {
        return ITEM_BACKSTAGE_PASSES;
    }
    else if (name == CONJURED) {
        return ITEM_CONJURED;
    }
    else {
        return ITEM_NORMAL;
    }
}

void GildedRose::updateQualityAgedBrie(int index)
{
    if (items[index].quality < MAX_QUALITY)
    {
        items[index].quality += 1;
    }
    items[index].sellIn--;
    if (items[index].sellIn < 0 && items[index].quality< MAX_QUALITY)
    {
        items[index].quality += 1;
    }
}

void GildedRose::updateQualityBackstagePasses(int index)
{
    if (items[index].quality < MAX_QUALITY)
    {
        items[index].quality += 1;

        if (items[index].sellIn <= 10 && items[index].quality < MAX_QUALITY)
        {
            items[index].quality += 1;
        }
        if (items[index].sellIn <= 5 && items[index].quality < MAX_QUALITY)
        {
            items[index].quality += 1;
        }
    }
    items[index].sellIn--;
    if (items[index].sellIn < 0)
    {
        items[index].quality = 0;
    }
    
}

void GildedRose::updateQualitySulfuras(int index)
{
}

void GildedRose::updateQualityConjured(int index)
{
    if (items[index].quality > MIN_QUALITY)
    {
        items[index].quality -= 2;
    }
    items[index].sellIn--;
    if (items[index].sellIn < 0 && items[index].quality>MIN_QUALITY)
    {
        items[index].quality -= 2;
    }
    if (items[index].quality < MIN_QUALITY)
    {
        items[index].quality = 0;
    }
}

void GildedRose::updateQualityNormal(int index)
{
    if (items[index].quality > MIN_QUALITY)
    {
        items[index].quality -= 1;
       
    }
    items[index].sellIn--;
    if (items[index].sellIn < 0 && items[index].quality>MIN_QUALITY)
    {
        items[index].quality -= 1;
    }
}

void GildedRose::updateQuality()
{
    for (int itemIndex = 0; itemIndex < items.size(); itemIndex++)
    {
        ItemType itemType = getItemTypeByName(items[itemIndex].name);
        switch (itemType) 
        {
        case ITEM_AGED_BRIE:
            updateQualityAgedBrie(itemIndex);
            break;
        case ITEM_SULFURAS:
            updateQualitySulfuras(itemIndex);
            break;
        case ITEM_BACKSTAGE_PASSES:
            updateQualityBackstagePasses(itemIndex);
            break;
        case ITEM_CONJURED:
            updateQualityConjured(itemIndex);
            break;
        case ITEM_NORMAL:
            updateQualityNormal(itemIndex);
            break;
        }
    }
}

