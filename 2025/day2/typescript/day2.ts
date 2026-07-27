let input = Bun.file("input.txt")
input = await input.text()
input = input.split(",")

let ans = 0
for (let i = 0; i < input.length; i++){
  const [start, end] = input[i].split("-")

  let startNum = Number(start) // convert start, end from string to number.
  let endNum = Number(end)

  for (let j = startNum; j <= endNum; j++) {
    let the_ID = j.toString()
    if (the_ID.length % 2 != 0) continue; // if odd-length, skip.

    if (the_ID.slice(0, the_ID.length / 2) == the_ID.slice(the_ID.length / 2, the_ID.length)) ans += j;
  }
}

console.log(ans)
