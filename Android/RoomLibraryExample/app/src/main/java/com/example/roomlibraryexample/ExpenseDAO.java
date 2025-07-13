package com.example.roomlibraryexample;


import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.DeleteTable;
import androidx.room.Insert;
import androidx.room.Query;
import androidx.room.Update;

import java.util.List;

@Dao
public interface ExpenseDAO {
    @Query("select * from Expense_Table") // will select all table data row by row and -
    List<Expense> getAllExpense();        // put them in a list and return the list

    @Insert
    void insertTxn(Expense expense);

    @Update
    void updateTxn(Expense expense);

    @Delete
    void deleteTxn(Expense expense);

    @Query("delete from Expense_Table")
    void clearAllTableTxn();



}
