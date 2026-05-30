```ui
text(character_name, "[color=#FFE400]Character name[/color]", 90)  enum(background, "Background", 80, ["Acolyte", "Charlatan", "Criminal", "Entertainer", "Folk Hero", "Guild Artisan", "Hermit", "Noble", "Outlander", "Sage", "Sailor", "Soldier", "Urchin"])enum(class_, "Class", 80, ["Artificer", "Barbarian", "Bard", "Cleric", "Druid", "Fighter", "Monk", "Paladin", "Ranger", "Rogue", "Sorcerer", "Warlock", "Wizard"])enum(species, "Species", 80, ["Human", "Elf", "Dwarf", "Halfling", "Gnome"])enum(subclass, "Subclass", 120, ["Path of the Berserker", "College of Lore", "Life Domain", "Champion", "Way of the Open Hand", "Oath of Devotion", "Hunter", "Thief", "Draconic Bloodline", "Wild Magic", "Fiend Patron", "School of Evocation", "Circle of the Land"]) int(level, "**Level**", 10, false)
// Heal Bar
hp_total(hp_current + hp_temp)
hp_pct(hp_total / hp_max)

// Dynamic bar color
hp_color(
    hp_total == 0 ? "#000000" :     
    hp_total > hp_max ? "#D4AF37" :
    hp_total == hp_max ? "#00AA00" : 
    hp_pct < 0.10 ? "#FF0000" :
    hp_pct < 0.20 ? "#F00001" :
    hp_pct < 0.30 ? "#E00002" :
    hp_pct < 0.40 ? "#D00003" :
    hp_pct < 0.50 ? "#C00004" :
    hp_pct < 0.60 ? "#B00005" :
    hp_pct < 0.70 ? "#A00006" :
    hp_pct < 0.80 ? "#900707" :
    hp_pct < 0.90 ? "#800808" :
                    "#700808"
)
hp_label(hp_total + "/" + hp_max)
if(hp_total > 0){
  bar(hp_total, hp_label, 760, 0, hp_max, hp_color)
}

if(hp_total < 1){
  text("💀") bar(hp_max, "", 760, 0, hp_max, "#000000") text("💀")
}
```