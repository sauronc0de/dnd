```ui
text(character_name, "[color=#FFE400]Name[/color]", 160)  enum(background, "Background", 80, ["Acolyte", "Charlatan", "Criminal", "Entertainer", "Folk Hero", "Guild Artisan", "Hermit", "Noble", "Outlander", "Sage", "Sailor", "Soldier", "Urchin"])enum(class_, "Class", 80, ["Artificer", "Barbarian", "Bard", "Cleric", "Druid", "Fighter", "Monk", "Paladin", "Ranger", "Rogue", "Sorcerer", "Warlock", "Wizard"])enum(species, "Species", 65, ["Human", "Elf", "Dwarf", "Halfling", "Gnome"])enum(subclass, "Subclass", 120, ["Path of the Berserker", "College of Lore", "Life Domain", "Champion", "Way of the Open Hand", "Oath of Devotion", "Hunter", "Thief", "Draconic Bloodline", "Wild Magic", "Fiend Patron", "School of Evocation", "Circle of the Land"]) int(level, "**Level**", 6, false)
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

hp_label("[color=#CC3333]HP[/color] ("+ hp_current + " + " + hp_temp + ") / " + hp_max)
if(hp_total > 0){
  bar(hp_total, hp_label, 550, 0, hp_max, hp_color) text("🛡 AC: [color=#FFD700]" + armor_class + "[/color]") text("     🪄 Bonus: ")text("[color=#00D1FF]" + spell_attack_bonus + "[/color]") text("DC:") text("[color=#7E00FF]" + spell_save_dc + "[/color]") 
  text("📦 [color=#00FF1F]Spell slots:[/color]") text(spell_slot_remaining) text("    [color=#D4AF37]💫 Sorcery[/color] ") text(sorcery_points + "/" + sorcery_points_max) button("Spend", 50, sorcery_points = sorcery_points > 0 ? sorcery_points-1: sorcery_points)  text("    [color=#AAAAFF]🎲 Hit Dice(1d6): [/color]") text(hit_dice_max-hit_dice_spent) text("/") text(hit_dice_max) button("Spend", 50, hit_dice_spent = hit_dice_spent == hit_dice_max ? hit_dice_spent : hit_dice_spent + 1) languages(["Common", "Gnomish", "Draconic"]) text("       [color=#66AAFF]🌐 Languages[/color]") multicheck(languages, "", 245, ["Common","Dwarvish","Elvish","Giant","Gnomish","Goblin","Halfling","Orc","Abyssal","Celestial","Deep Speech","Draconic","Infernal","Primordial","Sylvan","Undercommon","Thieves' Cant","Druidic"])
}

if(hp_total < 1){
  text("💀") bar(hp_max, "", 600, 0, hp_max, "#000000") text("💀")
}
```