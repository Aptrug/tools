This C function uses an algorithm called **Insertion Sort** to sort a linked list.

Imagine you are playing a card game. You are holding a messy deck of numbered cards in your hand (the `lst`), and you want to place them down on the table one by one to build a perfectly sorted pile (the `sorted_list`).

To do this, you take the top card from your hand, look at the pile on the table, find exactly where that specific card belongs, and insert it there. You repeat this until your hand is empty.

Here is a plain-English breakdown of what the code is doing, followed by a step-by-step example.

## The Code Translated

* `sorted_list = 0;`: This is your table. It starts empty (`NULL`).
* `while (lst)`: As long as you still have cards in your hand, keep going.
* `tmp_next = lst->next;`: Before you move the top card from your hand to the table, you need to remember where the *rest* of the cards in your hand are so you don't drop them!
* `insert_ptr = &sorted_list;`: Look at the very start of the sorted pile on the table.
* `while (*insert_ptr && !cmp(lst->data, (*insert_ptr)->data))`: Move your eyes down the sorted pile. Keep moving past cards **IF** there is a card there AND your current card is larger than it.
* `insert_ptr = &(*insert_ptr)->next;`: Move your eyes to the next spot.
* `lst->next = *insert_ptr;`: You found the spot! Make your card point to the rest of the pile that comes after it.
* `*insert_ptr = lst;`: Make the card that comes *before* it point to your card.
* `lst = tmp_next;`: Pick up the next messy card from your hand and start over.

---

## Step-by-Step Example

Let's sort a simple list of three numbers in ascending order: `[3] -> [1] -> [2]`

*Our compare function returns `1` if the first number is smaller or equal, and `0` if it is bigger.*

**Start of Game:**

* Hand (`lst`): `[3] -> [1] -> [2]`
* Table (`sorted_list`): `NULL` (Empty)

### Round 1: Card [3]

1. We pick up **`[3]`**. We save the rest of our hand (`tmp_next = [1]`).
2. We look at the table (`sorted_list`). It's completely empty.
3. Because the table is empty, we don't need to search for a spot. We just put `[3]` down.
4. **Current State:**
* Hand (`lst`): `[1] -> [2]`
* Table (`sorted_list`): `[3] -> NULL`



### Round 2: Card [1]

1. We pick up **`[1]`**. We save the rest of our hand (`tmp_next = [2]`).
2. We look at the table, starting at the very beginning. We see `[3]`.
3. We ask our compare function: "Does `[1]` belong before `[3]`?" Yes, it does!
4. So, we place `[1]` at the very front. We make `[1]` point to `[3]`, and we make `sorted_list` point to `[1]`.
5. **Current State:**
* Hand (`lst`): `[2]`
* Table (`sorted_list`): `[1] -> [3] -> NULL`



### Round 3: Card [2]

1. We pick up **`[2]`**. Our hand will be empty after this (`tmp_next = NULL`).
2. We look at the table, starting at the very beginning. We see `[1]`.
3. We ask: "Does `[2]` belong before `[1]`?" No. So we move our eyes to the next spot.
4. We look at the next card: `[3]`. We ask: "Does `[2]` belong before `[3]`?" Yes!
5. We found the spot. We wedge `[2]` right in between `[1]` and `[3]`.
6. **Final State:**
* Hand (`lst`): `NULL` (Empty!)
* Table (`sorted_list`): `[1] -> [2] -> [3] -> NULL`



Because our hand is empty, the `while (lst)` loop finishes, and the function returns the fully sorted pile on the table (`sorted_list`).
