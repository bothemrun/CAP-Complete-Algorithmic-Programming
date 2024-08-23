# csv2md.py
# converts Leetcode Log to README.md
import csv
CSV_PATH = "./Leetcode_Log.csv"
MD_PATH = "README.md"

if(__name__ == "__main__"):
	logs = []
	with open(CSV_PATH, "r") as f:
		csv_reader = csv.reader(f)
		for i, l in enumerate(csv_reader):
			if(l[1]=="" or i<3):
				continue
			print(l)
			print()
			dic = {
				"id": l[1],
				"problem": l[2],
				"level": l[3],
				"last_date": l[4],
				# "first_date": l[5],
				"difficulty": l[6],
				"hard_idea": l[7],
				"tags": l[9]
			}
			logs.append(dic)
	# end with open

	logs_level = { "hard":[], "medium":[], "easy":[] }
	for l in logs:
		logs_level[ l["level"] ].append(l)


	with open(MD_PATH, "w") as f:
		f.write(f'- [Hard Table](./{MD_PATH}#hard-table)\n')
		f.write(f'- [Medium Table](./{MD_PATH}#medium-table)\n')
		f.write(f'- [Easy Table](./{MD_PATH}#easy-table)\n')

		for level in ["hard", "medium", "easy"]:
			f.write(f'## {level} table\n')

			f.write("|#| Problem | Level |Diff| Hard_Idea | Tags |Last Date|\n")
			f.write("|-| ------- | -- |-| ---- | -------- |-|\n")


			"""
			l = logs[1]
			# must use different quotation marks for f-string and dict.
			# wrong: f.write(f"| {l["id"]} | {l["problem"]} | {l["level"]} | {l["difficulty"]} | {l["hard_idea"]} | tags |\n")
			"""
			for l in logs_level[level]:
				hard_idea = "Hard_Idea" if(l["hard_idea"] == "1") else ""
				f.write(f'| {l["id"]} | {l["problem"]} | {l["level"]} | {l["difficulty"]} | {hard_idea} | {l["tags"]} | {l["last_date"]} |\n')
		# end for level
	# end with open

# end main

