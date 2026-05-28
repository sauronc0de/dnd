```ui
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

text(character_name, "[color=#FFD166]Character[/color]", 220) text(player_name, "Player", 180)

text(class_name, "Class", 140) text(subclass_name, "Subclass", 140) text(species_name, "Species", 140) text(background_name, "Background", 160)

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