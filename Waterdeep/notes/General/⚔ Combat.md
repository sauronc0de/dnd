```ui
text("**Initiative:**") text(initiative) text(" **Speed:**") text(speed) text("**Size:**") text(size) text("**PP:**") text(passive_perception)
// Sorcery & Hit dice 
text("[color=#D4AF37]Sorcery[/color] ") text(sorcery_points + "/" + sorcery_points_max) button("Spend", 60, sorcery_points = sorcery_points > 0 ? sorcery_points-1: sorcery_points) text("[color=#AAAAFF]Hit Dice: [/color]") text(hit_dice_max-hit_dice_spent) text("/") text(hit_dice_max) button("Spend", 60, hit_dice_spent = hit_dice_spent == hit_dice_max ? hit_dice_spent : hit_dice_spent + 1)
```