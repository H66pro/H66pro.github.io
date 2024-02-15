package com.dch66app.activitytext

import android.content.Intent
import android.net.Uri
import android.os.Bundle
import android.view.Menu
import android.view.MenuItem
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import com.dch66app.activitytext.databinding.FirstLayoutBinding

class FirstActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.first_layout)
        val firstActivity = FirstLayoutBinding.inflate(layoutInflater)
        setContentView(firstActivity.root)
        firstActivity.butttttt.setOnClickListener {
//            val data = "Hello SecondActivity"
            val intent = Intent(this, SecondActivity::class.java)
//            intent.putExtra("extra_data", data)
            startActivityForResult(intent, 1)
        }
    }

    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        menuInflater.inflate(R.menu.main, menu)
        return true
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        when (item.itemId) {
            R.id.add_item -> Toast.makeText(this, "点击了Add", Toast.LENGTH_SHORT).show()
            R.id.remove_item -> Toast.makeText(this, "点击了Remove", Toast.LENGTH_SHORT).show()
        }
        return true
    }
}