```ui
text("**Initiative:**") text(initiative) text(" **Speed:**") text(speed) text("**Size:**") text(size) text("**PP:**") text(passive_perception)
// Sorcery & Hit dice 
text("[color=#D4AF37]💫 Sorcery[/color] ") text(sorcery_points + "/" + sorcery_points_max) button("Spend", 50, sorcery_points = sorcery_points > 0 ? sorcery_points-1: sorcery_points) text("[color=#AAAAFF]🎲 Hit Dice(1d6): [/color]") text(hit_dice_max-hit_dice_spent) text("/") text(hit_dice_max) button("Spend", 50, hit_dice_spent = hit_dice_spent == hit_dice_max ? hit_dice_spent : hit_dice_spent + 1)
languages(["Common", "Gnomish", "Draconic"])
multicheck(languages, "[color=#66AAFF]🌐 Languages[/color]", 235, ["Common","Dwarvish","Elvish","Giant","Gnomish","Goblin","Halfling","Orc","Abyssal","Celestial","Deep Speech","Draconic","Infernal","Primordial","Sylvan","Undercommon","Thieves' Cant","Druidic"])
```