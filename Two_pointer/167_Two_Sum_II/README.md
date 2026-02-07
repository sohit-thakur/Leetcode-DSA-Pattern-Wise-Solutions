# Two Sum II – Input Array Is Sorted

## 📌 Problem
Given a **1-indexed sorted array**, find two numbers such that they add up to a specific target.

---

## 🧠 Pattern
**Two Pointer**

---

## 💡 Approach
- Use two pointers `l` (start) and `r` (end)
- If sum < target → move `l`
- If sum > target → move `r`
- If equal → answer found
