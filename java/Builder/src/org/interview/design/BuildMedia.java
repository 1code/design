package org.interview.design;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

import junit.framework.TestCase;

class Media extends ArrayList {}
class Book extends Media {}
class Magazine extends Media {}
class Website extends Media {}

class MediaItem {
	private final String s;
	public MediaItem(final String s) { this.s = s; }
	@Override
	public String toString() { return this.s; }
}

class Chapter extends MediaItem {
	public Chapter(final String s) { super(s); }
}

class Article extends MediaItem {
	public Article(final String s) { super(s); }
}

class Webpage extends MediaItem {
	public Webpage(final String s) { super(s); }
}

class MediaBuilder {
	public void buildBase() {}
	public void addMediaItem(final MediaItem item) {};
	public Media getFinishedMedia() { return null; };
}

class BookBuilder extends MediaBuilder {
	private Book mBook;

	@Override
	public void buildBase() {
		System.out.println("build book base");
		mBook = new Book();
	}

	@Override
	public void addMediaItem(final MediaItem chapter) {
		System.out.println("add chapter: " + chapter);
		mBook.add(chapter);
	}

	@Override
	public Media getFinishedMedia() {
		return mBook;
	}
}

class MagazineBuilder extends MediaBuilder {
	private Magazine mMagazine;

	@Override
	public void buildBase() {
		System.out.println("build magazine base");
		mMagazine = new Magazine();
	}

	@Override
	public void addMediaItem(final MediaItem article) {
		System.out.println("add article: " + article);
		mMagazine.add(article);
	}

	@Override
	public Media getFinishedMedia() {
		return mMagazine;
	}
}

class WebsiteBuilder extends MediaBuilder {
	private Website mWebsite;

	@Override
	public void buildBase() {
		System.out.println("build website base");
		mWebsite = new Website();
	}

	@Override
	public void addMediaItem(final MediaItem webpage) {
		System.out.println("add webpage: " + webpage);
		mWebsite.add(webpage);
	}

	@Override
	public Media getFinishedMedia() {
		return mWebsite;
	}
}

class MediaDirector {
	private final MediaBuilder mMediaBuilder;
	public MediaDirector(final MediaBuilder mb) {
		mMediaBuilder = mb;
	}
	public Media produceMedia(final List put) {
		mMediaBuilder.buildBase();
		for (final Iterator it = put.iterator(); it.hasNext();)
			mMediaBuilder.addMediaItem((MediaItem) it.next());
		return mMediaBuilder.getFinishedMedia();
	}
}

public class BuildMedia extends TestCase {
	private final List input =  Arrays.asList(new MediaItem[] {
		new MediaItem("item1"), new MediaItem("item2"),
		new MediaItem("item3"), new MediaItem("item4")
	});

	public void testBook() {
		final MediaDirector bookDirector = new MediaDirector(new BookBuilder());
		final Book book = (Book) bookDirector.produceMedia(input);
		assertEquals(book.toString(), "[item1, item2, item3, item4]");
	}

	public void testMagazine() {
		final MediaDirector magazineDirector = new MediaDirector(new MagazineBuilder());
		final Magazine magazine = (Magazine) magazineDirector.produceMedia(input);
		assertEquals(magazine.toString(), "[item1, item2, item3, item4]");
	}

	public void testWebsite() {
		final MediaDirector websiteDirector = new MediaDirector(new WebsiteBuilder());
		final Website website = (Website) websiteDirector.produceMedia(input);
		assertEquals(website.toString(), "[item1, item2, item3, item4]");
	}

	public static void main(final String[] args) {
		junit.textui.TestRunner.run(BuildMedia.class);
	}
}
