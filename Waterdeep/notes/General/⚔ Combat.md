```ui
text("**Initiative:**") text(initiative) text(" **Speed:**") text(speed) text("**Size:**") text(size) text("**PP:**") text(passive_perception)
// Hit dice 
text("[color=#AAAAFF]Hit Dice: [/color]") text(hit_dice_max-hit_dice_spent) text("/") text(hit_dice_max) button("Spend", 60, hit_dice_spent = hit_dice_spent == hit_dice_max ? hit_dice_spent : hit_dice_spent + 1)
```