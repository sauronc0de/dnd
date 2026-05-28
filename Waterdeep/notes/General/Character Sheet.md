# Main
```UI
character_name("New Hero")
player_name("")
class_name("Fighter")
subclass_name("")
species_name("Human")
background_name("")
level(1)
xp(0)

alignment("Neutral")
campaign_name("")

hp_current(12)
hp_max(12)
temp_hp(0)

ac(16)
initiative(2)
speed(30)
proficiency_bonus(2)

hit_dice("1d10")
death_successes(0)
death_failures(0)

text(character_name, "[color=#FFD166]Character[/color]", 220)
text(player_name, "Player", 180)

text(class_name, "Class", 140)
text(subclass_name, "Subclass", 140)
text(species_name, "Species", 140)
text(background_name, "Background", 160)

int(level, "[color=#7FDBFF]Level[/color]", 80, true) int(xp, "XP", 120, true)

enum(alignment, "Alignment", 180,
["Lawful Good","Neutral Good","Chaotic Good",
"Lawful Neutral","Neutral","Chaotic Neutral",
"Lawful Evil","Neutral Evil","Chaotic Evil"])

text(campaign_name, "Campaign", 200)

slider(hp_current, "[color=#FF5555]Current HP[/color]", 240, 0, 200)
slider(hp_max, "Max HP", 240, 1, 200)
slider(temp_hp, "[color=#66CCFF]Temp HP[/color]", 240, 0, 100)

int(ac, "Armor Class", 80, true) int(initiative, "Initiative", 80, true) int(speed, "Speed", 80, true)
int(proficiency_bonus, "Prof Bonus", 80, true)

text(hit_dice, "Hit Dice", 100)

slider(death_successes, "Death Saves Success", 180, 0, 3)
slider(death_failures, "Death Saves Failure", 180, 0, 3)

if(death_failures >= 3) {
  text("[color=#FF4444]Character is DEAD[/color]")
}
if(death_successes >= 3) {
  text("[color=#44FF88]Character stabilised[/color]")
}
```
# Stats
```UI
strength(10)
dexterity(10)
constitution(10)
intelligence(10)
wisdom(10)
charisma(10)

saving_throws([])
skills([])

text("[color=#FFD166]Ability Scores[/color]")

slider(strength,     "STR", 220, 1, 30)
slider(dexterity,    "DEX", 220, 1, 30)
slider(constitution, "CON", 220, 1, 30)
slider(intelligence, "INT", 220, 1, 30)
slider(wisdom,       "WIS", 220, 1, 30)
slider(charisma,     "CHA", 220, 1, 30)

multicheck(
saving_throws,
"[color=#7FDBFF]Saving Throw Proficiencies[/color]",
280,
["STR","DEX","CON","INT","WIS","CHA"]
)

multicheck(
skills,
"[color=#7FDBFF]Skill Proficiencies[/color]",
320,
[
"Acrobatics",
"Animal Handling",
"Arcana",
"Athletics",
"Deception",
"History",
"Insight",
"Intimidation",
"Investigation",
"Medicine",
"Nature",
"Perception",
"Performance",
"Persuasion",
"Religion",
"Sleight of Hand",
"Stealth",
"Survival"
]
)
```


# Equipment & Training Proficiencies
```UI
armor_training([])
tool_training([])
vehicle_training([])
other_training("")

multicheck(
armor_training,
"Armor Training",
260,
["Light Armor","Medium Armor","Heavy Armor","Shields"]
)

multicheck(
tool_training,
"Tool Proficiencies",
300,
[
"Thieves' Tools",
"Smith's Tools",
"Herbalism Kit",
"Navigator's Tools",
"Poisoner's Kit",
"Forgery Kit",
"Disguise Kit",
"Musical Instrument"
]
)

multicheck(
vehicle_training,
"Vehicle Training",
240,
["Land Vehicles","Water Vehicles","Air Vehicles"]
)

text(other_training, "Other Proficiencies", 320)
```



# Weapons
```UI
weapons([
  {name:"Longsword", tooltip:"1d8 Slashing"},
  {name:"Shortbow", tooltip:"1d6 Piercing"},
  {name:"Dagger", tooltip:"Thrown, finesse"}
])

list(weapons, "[color=#FFD166]Weapons[/color]", 340, true)
```

# Class features
```UI
class_features([
  {name:"Second Wind", tooltip:"Bonus Action heal"},
  {name:"Action Surge", tooltip:"Extra action once per short rest"}
])

list(class_features, "[color=#FFD166]Class Features[/color]", 360, true)
# Species traits
species_traits([
  {name:"Darkvision", tooltip:"See in darkness"},
  {name:"Brave", tooltip:"Advantage vs fear"}
])

list(species_traits, "[color=#FFD166]Species Traits[/color]", 360, true)
```


# Feats
```UI
feats([
  {name:"Tough", tooltip:"+2 HP per level"},
  {name:"Alert", tooltip:"+5 initiative"}
])

list(feats, "[color=#FFD166]Feats[/color]", 340, true)
```

# Spells
```UI
spellcasting_ability("Wisdom")
spell_save_dc(13)
spell_attack_bonus(5)

enum(
spellcasting_ability,
"Spellcasting Ability",
180,
["Strength","Dexterity","Constitution","Intelligence","Wisdom","Charisma"]
)

int(spell_save_dc, "Spell Save DC", 100, true)
int(spell_attack_bonus, "Spell Attack", 100, true)
```
## Spell slots
```UI
slot_1(2)
slot_2(0)
slot_3(0)
slot_4(0)
slot_5(0)
slot_6(0)
slot_7(0)
slot_8(0)
slot_9(0)

slider(slot_1, "Level 1 Slots", 240, 0, 4)
slider(slot_2, "Level 2 Slots", 240, 0, 4)
slider(slot_3, "Level 3 Slots", 240, 0, 4)
slider(slot_4, "Level 4 Slots", 240, 0, 4)
slider(slot_5, "Level 5 Slots", 240, 0, 4)
slider(slot_6, "Level 6 Slots", 240, 0, 4)
slider(slot_7, "Level 7 Slots", 240, 0, 4)
slider(slot_8, "Level 8 Slots", 240, 0, 4)
slider(slot_9, "Level 9 Slots", 240, 0, 4)
## Cantriprs & Prepared spells
cantrips([
  {name:"Sacred Flame"},
  {name:"Thaumaturgy"}
])

prepared_spells([
  {name:"Bless"},
  {name:"Healing Word"},
  {name:"Shield of Faith"}
])

list(cantrips, "[color=#66CCFF]Cantrips[/color]", 320, true)

list(prepared_spells,
"[color=#FFD166]Prepared Spells[/color]",
360,
true)
```


# Background
```UI
background_traits([
  {name:"Military Rank", tooltip:"Soldiers loyal to your former military organization recognize your authority"}
])

list(background_traits, "[color=#FFD166]Background Features[/color]", 360, true)
```


## Appearance
```UI
age(25)
height_text("5'10")
weight_text("170 lb")
eyes("Brown")
hair("Black")
skin("Tan")

int(age, "Age", 80, true)

text(height_text, "Height", 120)
text(weight_text, "Weight", 120)

text(eyes, "Eyes", 120)
text(hair, "Hair", 120)
text(skin, "Skin", 120)
```


## Backstory & Personality
## Languages
```UI
languages([
  {name:"Common"},
  {name:"Elvish"},
  {name:"Dwarvish"}
])

list(languages, "[color=#FFD166]Languages[/color]", 260, true)
```


## Equipment
```UI
inventory_items([
  {
    name:"Backpack",
    image:"assets/icons/backpack.png",
    tooltip:"Standard backpack",
    quantity:1
  },
  {
    name:"Torch",
    image:"assets/icons/fire.png",
    tooltip:"Provides light",
    quantity:10,
    color:"#FFAA33"
  },
  {
    name:"Rations",
    image:"assets/icons/food.png",
    tooltip:"One day ration",
    quantity:5
  },
  {
    name:"Potion",
    image:"assets/icons/potion.png",
    tooltip:"Healing potion",
    quantity:2,
    color:"#FF4444"
  }
])

inventory(
inventory_items,
"[color=#FFD166]Inventory[/color]",
420,
3,
5
)
```