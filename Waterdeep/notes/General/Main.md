```ui
text(character_name)
text(background)
enum(class_, "Class", 160, ["Artificer", "Barbarian", "Bard", "Cleric", "Druid", "Fighter", "Monk", "Paladin", "Ranger", "Rogue", "Sorcerer", "Warlock", "Wizard"])
enum(species, "Species", 160, ["Human", "Elf", "Dwarf", "Halfling", "Gnome"])
text(subclass, "Subclass", 180)
int(level, "Level", 70, true)

text("")

int(base_armor_class, "Base AC", 90, true) checkbox(shield_equipped, "Shield")
text(armor_class, "Armor class", 80)

int(hp_current, "HP current", 90, true)
int(hp_temp, "Temp HP", 80, true)
int(hp_max, "HP max", 80, true)

int(hit_dice_spent, "Hit dice spent", 110, true)
int(hit_dice_max, "Hit dice max", 100, true)

int(initiative, "Initiative", 90, true)
text(speed, "Speed", 80)
text(size, "Size", 90)
int(passive_perception, "Passive Perception", 140, true)
```
