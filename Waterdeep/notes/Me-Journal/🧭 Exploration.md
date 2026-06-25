```mermeid
Adventure Tracker
kanban
  a[🔍 To Investigate]
  a[📝 Available]
  a[⚔ In Progress]
    c1[Necklace]: Fill the necklace with charms related to my 7 lifes
  a[✅ Completed]
  a[❌ Failed]
  ```[```]
  ```[```]
```

```ui
enum(selected_map, "🗺 Select", 220, ["Faerun", "Waterdeep"])

if(starts_with(selected_map, "Faerun")){ map(faerun_map, 500, 500) }
if(starts_with(selected_map, "Waterdeep")){ map(waterdeep_map, 500, 500) }
```