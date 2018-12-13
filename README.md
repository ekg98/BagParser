# BagParser 
Cmangos Bag Parser by ekg98.  Converts 28 slot bags to 32 slot bags...

https://github.com/cmangos/mangos-classic/commit/ac9a3bd7dab183f1f3fae6d16f4baa3a2993fc00

This commit messed up the bags inside classic.  The datafield needs to be 122 words total for the new 32 slot bags.

The previous total for 28 slot bags is 106 words.

1) run the following query on your db.  change mangos to match the name of your db.  Thanks to crito for the query.
SELECT ii.guid, it.name, ii.data FROM item_instance AS ii INNER JOIN character_inventory AS ci ON (ii.guid = ci.item) INNER JOIN mangos.item_template AS it ON (ci.item_template = it.entry) WHERE it.class = 1;

2) run BagParser.
3) copy the data field from item_instance's effected bag and paste it into bag parser and hit enter.
4) copy BagParsers output and paste it into your db's data field in the same spot over writing the previous 106 word long data
   field with the new 122 word long data field.
5) run cmangos as normal.

